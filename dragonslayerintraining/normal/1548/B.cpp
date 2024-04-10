#include <cstdio>
#include <algorithm>
#include <cstdlib>

int ans;
long long as[200005];
long long gs[200005];

long long gcd(long long a,long long b){
  return b?gcd(b,a%b):a;
}

void solve(int l,int r){
  if(l>r) return;
  int m=(l+r)/2;
  gs[m]=0;
  for(int i=m-1;i>=l;i--){
    gs[i]=gcd(gs[i+1],llabs(as[i]-as[m]));
  }
  for(int i=m+1;i<=r;i++){
    gs[i]=gcd(gs[i-1],llabs(as[i]-as[m]));
  }
  int a=l;
  for(int b=m;b<=r;b++){
    if(gs[b]==1) break;
    while(gcd(gs[a],gs[b])==1){
      a++;
    }
    ans=std::max(ans,b-a+1);
  }
  solve(l,m-1);
  solve(m+1,r);
}


void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%lld",&as[i]);
  }
  ans=0;
  solve(0,N-1);
  printf("%d\n",ans);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}