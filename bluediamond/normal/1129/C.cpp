#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a,int b){
  a=add(a,b);
}

const int N=3000+7;
int n,a[N],dp[N][N],lcp[N][N];
bool ok[N];

bool match(int l1,int l2,int len){
  for(int i=0;i<len;i++){
    if(a[l1+i]!=a[l2+i]) return 0;
  }
  return 1;
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

  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  /// "0011", "0101", "1110", and "1111".

  for(int i=1;i<=n;i++){
    ok[i]=1;
    if(a[i]==0&&a[i+1]==0&&a[i+2]==1&&a[i+3]==1) ok[i]=0;
    if(a[i]==0&&a[i+1]==1&&a[i+2]==0&&a[i+3]==1) ok[i]=0;
    if(a[i]==1&&a[i+1]==1&&a[i+2]==1&&a[i+3]==0) ok[i]=0;
    if(a[i]==1&&a[i+1]==1&&a[i+2]==1&&a[i+3]==1) ok[i]=0;
  }

  for(int l=n;l>=1;l--){
    for(int r=l;r<=n;r++){
      for(int k=1;k<=min(4,r-l+1);k++){
        if(k==4&&!ok[l]){
          continue;
        }
        if(k==r-l+1){
          addup(dp[l][r],1);
        }
        addup(dp[l][r],dp[l+k][r]);
      }
    }
  }

  for(int i=n;i>=1;i--){
    for (int j=n;j>=1;j--){
      if(a[i]==a[j]){
        lcp[i][j]=1+lcp[i+1][j+1];
      }
    }
  }
  int sol=0;
  for(int r=1;r<=n;r++){
    int low=1,high=r,f=r+1;
    while(low<=high){
      int len=(low+high)/2;
      bool ok=1;
      for(int r2=len;r2<r;r2++){
        if(lcp[r2-len+1][r-len+1]>=len){
          ok=0;
        }
      }
      if(ok){
        high=len-1;
        f=len;
      }else{
        low=len+1;
      }
    }
    for(int len=f;len<=r;len++){

      if(ok){
        ///cout<<len<<" ";
        addup(sol,dp[r-len+1][r]);
      }
    }
    //cout<<"\n";
    cout<<sol<<"\n";
  }


  return 0;
}