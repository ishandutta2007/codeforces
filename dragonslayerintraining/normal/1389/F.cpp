#include <cstdio>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>

class LazyPropSegtree{
  struct Lazy{
    int add;
    //default to identity
    Lazy(int add=0):add(add){
    }
    void apply(const Lazy& lazy){
      add+=lazy.add;
    }
  };
  struct Data{
    int val;
    //default to identity
    Data(int val=std::numeric_limits<int>::min()):val(val){
    }
    void apply(const Lazy& lazy){
      val+=lazy.add;
    }
  };
  //doesn't need to be commutative
  Data combine(Data a,Data b){
    return Data(std::max(a.val,b.val));
  }
  struct Node{
    Lazy lazy;
    Data data;
  };
  std::vector<Node> st;
  int N;
  void push(int w,int L,int R){
    //propagate to children
    if(R-L>1){
      st[w*2+1].lazy.apply(st[w].lazy);
      st[w*2+2].lazy.apply(st[w].lazy);
    }
    //update node
    st[w].data.apply(st[w].lazy);
    //clear lazy
    st[w].lazy=Lazy();
  }
  //precondition: children's lazy are cleared
  void pull(int w,int L,int R){
    st[w].data=combine(st[w*2+1].data,st[w*2+2].data);
  }
  void build(int w,int L,int R){
    if(R-L==1){
      //st[w].lazy already identity
      st[w].data=Data(0);
    }else{
      int M=(L+R)/2;
      build(w*2+1,L,M);
      build(w*2+2,M,R);
      pull(w,L,R);
    }
  }   
  //postcondition: w's lazy is cleared 
  void update_add(int w,int L,int R,int a,int b,int v){
    push(w,L,R);
    if(a>=R||b<=L) return;
    if(a<=L&&b>=R){
      st[w].lazy=Lazy{v};
      push(w,L,R);
    }else{
      int M=(L+R)/2;
      update_add(w*2+1,L,M,a,b,v);
      update_add(w*2+2,M,R,a,b,v);
      pull(w,L,R);
    }
  }
  //postcondition: w's lazy is cleared 
  Data query_max(int w,int L,int R,int a,int b){
    push(w,L,R);
    if(a>=R||b<=L) return Data(); //identity
    if(a<=L&&b>=R){
      return st[w].data;
    }else{
      int M=(L+R)/2;
      return combine(query_max(w*2+1,L,M,a,b),
		     query_max(w*2+2,M,R,a,b));
    }
  }
public:
  LazyPropSegtree(int N):st(N*4),N(N){
    build(0,0,N);
  }
  void update_add(int a,int b,int v){
    update_add(0,0,N,a,b,v);
  }
  Data query_max(int a,int b){
    return query_max(0,0,N,a,b);
  }
};

//Testing on https://codeforces.com/contest/1389/problem/F

int ls[200005];
int rs[200005];
int ts[200005];

std::vector<int> bucket[2][400005];

int main(){
  int N;
  scanf("%d",&N);
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    scanf("%d %d %d",&ls[i],&rs[i],&ts[i]);
    cps[ls[i]],cps[rs[i]];
  }
  int last=0;
  for(auto& it:cps){
    it.second=++last;
  }
  for(int i=0;i<N;i++){
    bucket[ts[i]-1][cps[rs[i]]].push_back(cps[ls[i]]);
  }
  LazyPropSegtree dp[2]={LazyPropSegtree(last+1),LazyPropSegtree(last+1)};
  for(int i=1;i<=last;i++){
    for(int t=0;t<2;t++){
      for(int l:bucket[t][i]){
	dp[t].update_add(0,l,1);
      }
      dp[t^1].update_add(i,i+1,dp[t].query_max(0,i).val);
    }
  }
  printf("%d\n",std::max(dp[0].query_max(0,last+1).val,
			 dp[1].query_max(0,last+1).val));
}