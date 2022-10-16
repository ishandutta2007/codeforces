#include <cstdio>
#include <cstring>
#include <cassert>
#include <array>

char str[100005];
std::array<int,27> next[100005];
std::array<int,27> prev[100005];
std::array<int,27> nextgrundy[100005];
std::array<int,27> prevgrundy[100005];
int prefix[100005];
int N;

int query(int L,int R);

int getnextgrundy(int i,int c){
  return (nextgrundy[i][c]!=-1)?nextgrundy[i][c]:(nextgrundy[i][c]=query(i,next[i][c]));
}
int getprevgrundy(int i,int c){
  return (prevgrundy[i][c]!=-1)?prevgrundy[i][c]:(prevgrundy[i][c]=query(prev[i][c],i));
}
int getprefix(int i){
  return (prefix[i]!=-1)?prefix[i]:(prefix[i]=getprefix(prev[i][str[i]])^getprevgrundy(i,str[i]));
}

int query(int L,int R){
  unsigned int mask=0;
  for(int c=0;c<27;c++){
    //Skip if no c in (L,R)
    if(next[L][c]>=R) continue;
    mask|=(1ULL<<(getnextgrundy(L,c)^getprevgrundy(R,c)^getprefix(next[L][c])^getprefix(prev[R][c])));
  }
  //return mex
  for(int k=0;k<27;k++){
    if((mask&(1<<k))==0){
      return k;
    }
  }
  assert(0);
}

int main(){
  scanf("%s",str+1);
  N=strlen(str+1);
  for(int i=1;i<=N;i++){
    str[i]-='a';
  }
  str[0]=str[N+1]=26;
  for(int i=1;i<=N+1;i++){
    prev[i]=prev[i-1];
    prev[i][str[i-1]]=i-1;
  }
  std::fill(next[N+1].begin(),next[N+1].end(),N+1);
  for(int i=N;i>=0;i--){
    next[i]=next[i+1];
    next[i][str[i+1]]=i+1;
  }
  for(int i=0;i<=N+1;i++){
    nextgrundy[i].fill(-1);
    prevgrundy[i].fill(-1);
  }
  for(int i=0;i<=N+1;i++){
    prefix[i]=-1;
  }
  prefix[0]=0;
  int M;
  scanf("%d",&M);
  while(M-->0){
    int L,R;
    scanf("%d %d",&L,&R);
    if(query(L-1,R+1)){
      printf("Alice\n");
    }else{
      printf("Bob\n");
    }
  }
  return 0;
}