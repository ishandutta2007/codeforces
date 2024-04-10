#include <cstdio>
#include <algorithm>

int N;
int ls[300005];
int rs[300005];

int solve(int ex,int& li,int& ri){
  li=-1,ri=-1;
  for(int i=0;i<N;i++){
    if(i==ex) continue;
    if(li==-1||ls[i]>ls[li]){
      li=i;
    }
    if(ri==-1||rs[i]<rs[ri]){
      ri=i;
    }
  }
  return std::max(0,rs[ri]-ls[li]);
}

int solve(int ex){
  int ign1,ign2;
  return solve(ex,ign1,ign2);
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&ls[i],&rs[i]);
  }
  int li,ri;
  solve(-1,li,ri);
  printf("%d\n",std::max(solve(li),solve(ri)));
}