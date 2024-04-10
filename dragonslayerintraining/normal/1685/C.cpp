#include <cstdio>
#include <algorithm>

int N;
char str[200005];

int pref[200005];

void solve(){
  scanf("%d %s",&N,str);
  N*=2;
  pref[0]=0;
  for(int i=0;i<N;i++){
    pref[i+1]=pref[i]+((str[i]=='(')?1:-1);
  }
  if(*std::min_element(pref,pref+N)>=0){
    printf("0\n");
    return;
  }
  int l=0;
  for(int i=0;i<=N;i++){
    if(pref[i]<0) break;
    if(pref[i]>pref[l]){
      l=i;
    }
  }
  int r=N;
  for(int i=N;i>=0;i--){
    if(pref[i]<0) break;
    if(pref[i]>pref[r]){
      r=i;
    }
  }
  if(*std::max_element(pref+l,pref+r)<=pref[l]+pref[r]){
    printf("1\n%d %d\n",l+1,r);
    return;
  }
  int m=std::max_element(pref,pref+N)-pref;
  printf("2\n%d %d\n%d %d\n",1,m,m+1,N);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}