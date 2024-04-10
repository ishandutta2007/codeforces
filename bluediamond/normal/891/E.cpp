#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long double ld;
typedef long long ll;

const int M=(int)1e9+7;

int add(int a,int b) {
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}

int mul(int a,int b){
  return a*(ll)b%M;
}

int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}

int dv(int a,int b){
  return mul(a,pw(b,M-2));
}

void addup(int &a,int b){
  a=add(a,b);
}

const int N=5000+7;
int n,a[N],k,dp[N][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n>>k;
  for (int i=0;i<n;i++)cin>>a[i];

  dp[0][0]=1;
  for (int i=0;i<n;i++){
    for (int c=0;c<=i;c++){
      addup(dp[i+1][c],dp[i][c]);
      addup(dp[i+1][c+1],mul(a[i],dp[i][c]));
    }
  }

  int sol=0;
  for (int negative=0;negative<=n;negative++){
    if (negative>k) break;
    int take=n-negative;
    /**for (int mask=0;mask<(1<<n);mask++){
      int bits=0,prod=1;
      for (int i=0;i<n;i++){
        if(mask&(1<<i)){
          bits++;
          prod=mul(prod,a[i]);
        }
      }
      if (bits!=take)continue;


      int current=prod;
      if (negative&1){
        current=add(0,-current);
      }

      for (int j=0;j<negative;j++){
        current=mul(current,(k-j));
      }
      current=mul(current,pw(n,k-negative));
      addup(sol, current);
    }**/
    int current=dp[n][take];
    if (negative&1){
      current=add(0,-current);
    }

    for (int j=0;j<negative;j++){
      current=mul(current,(k-j));
    }
    current=mul(current,pw(n,k-negative));
    addup(sol, current);
  }
  sol=dv(sol,pw(n,k));
  int prod=1;
  for (int i=0;i<n;i++){
    prod=mul(prod,a[i]);
  }

  cout<<add(prod,-sol)<<"\n";

  return 0;

  /**



  sum for all options of (a[1]-1-1-1-1)*(a[2]-1-1-1-1-1-1-1)*...*(a[n]-1-1-1-1-1-1)


  aleg {i1, ..., iz}

  am (-1)^z * (prod of others)
  de cate ori adaug valoarea asta?


  k-z -1 uri de pus

  n^(k-z)

  **/




  return 0;
}