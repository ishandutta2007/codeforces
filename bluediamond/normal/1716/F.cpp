#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M=998244353;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
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
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}

/// how many tuplets of length k of the elements 1,...,n have exactly d distinct values
/**
fix the distinct values, the elements are numbered from

**/
signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen("___input___.txt","r",stdin);
 int k=2000+7;
    vector<vector<int>> dp(k+1,vector<int> (k+1,0));
    dp[0][0]=1;
    for (int len=0;len<k;len++){
      for(int d=0;d<=len;d++) {
        addup(dp[len+1][d],mul(d,dp[len][d]));
        addup(dp[len+1][d+1],mul(1,dp[len][d]));
      }
    }
  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    int n,m,k,x,odd;
    cin>>n>>m>>k;
    if(m==1){
      cout<<pw(n,k)<<"\n";
      continue;
    }
    odd=m-m/2;
    int sol=0;

    int lol=1;
    for(int d=1;d<=min(n,k);d++) {
      mulup(lol,n-d+1);
      /// atatea elemente sunt distincte
      int contrib=1;
      mulup(contrib,pw(m,n-d));
      mulup(contrib,pw(odd,d));
      addup(sol,mul(contrib,dp[k][d],lol));
    }

    cout<<sol<<"\n";
  }
  //assert(H==730637159);
}
/**
contrib(t)=m^(n-distinct)*odd^distinct
f(distinct) = how many tuplets (i1, i2, ..., in) with y distinct elements are there
**/