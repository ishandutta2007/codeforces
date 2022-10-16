#include <cstdio>
#include <array>
#include <cassert>
#include <set>

int as[2005];

struct State{
  std::array<int,30> uf;
  int has;
  State(){
    for(int i=0;i<30;i++){
      uf[i]=i;
    }
    has=0;
  }
  bool good(){
    int cc=-1;
    for(int k=0;k<30;k++){
      if(has&(1<<k)){
	int tmp=find(k);
	if(cc==-1){
	  cc=tmp;
	}else if(cc!=tmp){
	  return false;
	}
      }
    }
    return true;
  }
  int find(int a){
    while(uf[a]!=a) a=uf[a];
    return a;
  }
  void add(int mask){
    for(int l=0;l<30;l++){
      if(mask&(1<<l)){
	for(int k=l+1;k<30;k++){
	  if(mask&(1<<k)){
	    uf[find(l)]=find(k);
	  }
	}
      }
    }
    has|=mask;
  }
};

int N;

bool solve1(int L,int R,State st,int zeros){
  if(R-L==1){
    State st1=st,st2=st;
    st1.add(as[L]-1);
    if(as[L]>1&&st1.good()){
      printf("%d\n",zeros+1);
      for(int j=0;j<N;j++){
	if(j) printf(" ");
	printf("%d",(L==j)?(as[j]-1):as[j]);
      }
      printf("\n");
      return true;
    }
    st2.add(as[L]+1);
    if(st2.good()){
      printf("%d\n",zeros+1);
      for(int j=0;j<N;j++){
	if(j) printf(" ");
	printf("%d",(L==j)?(as[j]+1):as[j]);
      }
      printf("\n");
      return true;
    }
    return false;
  }else{
    int M=(L+R)/2;
    State stl=st,str=st;
    for(int i=L;i<M;i++){
      str.add(as[i]);
    }
    for(int i=M;i<R;i++){
      stl.add(as[i]);
    }
    if(solve1(L,M,stl,zeros)) return true;
    if(solve1(M,R,str,zeros)) return true;
    return false;
  }
}

void solve(){
  scanf("%d",&N);
  int zeros=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(as[i]==0){
      zeros++;
      as[i]=1;
    }
  }
  struct State all;
  for(int i=0;i<N;i++){
    all.add(as[i]);
  }
  if(all.good()){
    printf("%d\n",zeros);
    for(int i=0;i<N;i++){
      if(i) printf(" ");
      printf("%d",as[i]);
    }
    printf("\n");
    return;
  }
  if(solve1(0,N,State(),zeros)){
    return;
  }
  std::set<int> ccs;
  int high=-1;
  for(int k=0;k<30;k++){
    if(all.has&(1<<k)){
      if(!ccs.count(all.find(k))){
	ccs.insert(all.find(k));
	high=k;
	//printf("high:=%d\n",high);
      }
    }
  }
  assert(high!=-1);
  for(int i=0;i<N;i++){
    if(as[i]&(1<<high)){
      as[i]--;
      bool success=solve1(0,N,State(),zeros+1);
      assert(success);
      return;
    }
  }
  assert(0);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}