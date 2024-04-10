#include <bits/stdc++.h>

using namespace std;

bool home = 1;
const int N=(int) 3e5+7;
int n,q,mod,fib[N],a[N],d[N],jump[N],cnt0=0;

int rep(int x){
  x%=mod;
  if(x<0) x+=mod;
  assert(0<=x&&x<mod);
  return x;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>q>>mod;
  fib[1]=1;
  fib[2]=1;
  for(int i=3;i<N;i++){
    fib[i]=rep(fib[i-1]+fib[i-2]);
  }

  n++;

  for(int i=2;i<=n;i++){
    cin>>a[i];
  }
  for(int i=2;i<=n;i++){
    int b;
    cin>>b;
    a[i]=rep(a[i]-b);
  }
  for(int i=1;i<=n;i++){
    d[i]=rep(a[i]-a[i-1]-a[i-2]);
    cnt0+=(d[i]==0);
  }

  while(q--){
    string type;
    int l,r;
    cin>>type>>l>>r;
    l++;
    r++;
    int sgn;
    if(type=="A"){
      sgn=+1;
    }else{
      sgn=-1;
      assert(type=="B");
    }
    jump[l]=r+1;
    jump[r+1]=r+2;
    jump[r+2]=n+1;

    for(int i=l;i<=min(n,r+2);i=jump[i]){
      cnt0-=(d[i]==0);
      if(i==l){
        d[i]=rep(d[i]+fib[1]*sgn);
      }else{
        if(i==r+2){
          d[i]=rep(d[i]-fib[r-l+1]*sgn);
        }
        if(i==r+1){
          d[i]=rep(d[i]-fib[r-l+2]*sgn);
        }
      }
      cnt0+=(d[i]==0);
    }
    bool ok=(cnt0==n);
    if(ok){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }



  return 0;
}