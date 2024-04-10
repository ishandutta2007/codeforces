#include <iostream>
#include <vector>
#include <stdint.h>

typedef struct Exhibit{
  int v,w;
  Exhibit(int v,int w):v(v),w(w){
  }
}Exhibit;

std::vector<Exhibit> exh;
std::vector<int> begin,end;
int N,K;

struct DP{
  int dp[1001];
  DP(){
    std::fill(dp,dp+1001,0);
  }
  void insert(Exhibit e){
    for(int i=1000;i>=e.w;i--){
      dp[i]=std::max(dp[i],dp[i-e.w]+e.v);
    }
  }
};


std::vector<Exhibit> st[30000*4];
int qs[30000*4];

void insert(int w,int L,int R,int a,int b,Exhibit e){
  if((a>=R)||(b<=L)){
    return;
   }
  if((a<=L)&&(b>=R)){
    st[w].push_back(e);
    return;
  }
  int M=(L+R)/2;
  insert(w*2+1,L,M,a,b,e);
  insert(w*2+2,M,R,a,b,e);
}

void query(int w,int L,int R,int i){
  if((i>=R)||(i<L)){
    return;
  }
  qs[w]++;
  if(R-L==1){
    return;
  }
  int M=(L+R)/2;
  query(w*2+1,L,M,i);
  query(w*2+2,M,R,i);
}

std::vector<struct DP> stk;
void dfs(int w,int L,int R){
  if(qs[w]==0){
    return;
  }
  stk.push_back(stk.back());
  for(Exhibit e:st[w]){
    stk.back().insert(e);
  }
  if(R-L==1){
    int64_t sum=0;
    for(int i=K;i>0;i--){
      sum=(sum*10000019L+stk.back().dp[i])%1000000007;
    }
    for(int i=0;i<qs[w];i++){
      std::cout<<sum<<std::endl;
    }
  }else{
    int M=(L+R)/2;
    dfs(w*2+1,L,M);
    dfs(w*2+2,M,R);
  }
  stk.pop_back();
}

int main(){
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    int V,W;
    std::cin>>V>>W;
    exh.emplace_back(V,W);
    begin.push_back(0);
    end.push_back(1e9);
  }
  int Q;
  std::cin>>Q;
  for(int i=0;i<Q;i++){
    int type;
    std::cin>>type;
    switch(type){
    case 1:{
      int V,W;
      std::cin>>V>>W;
      exh.emplace_back(V,W);
      begin.push_back(i);
      end.push_back(1e9);
      break;
    }
    case 2:{
      int X;
      std::cin>>X;
      X--;
      end[X]=i;
      break;
    }
    case 3:{
      query(0,0,Q,i);
      break;
    }
    }
  }
  for(int i=0;i<exh.size();i++){
    insert(0,0,Q,begin[i],end[i],exh[i]);
  }
  stk.emplace_back();
  dfs(0,0,Q);
  return 0;
}