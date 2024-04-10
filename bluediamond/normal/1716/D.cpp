#include <bits/stdc++.h>

using namespace std;
const int M=998244353;
typedef long long ll;
int add(int a,int b){
  a+=b;
  if(a>=M) return a-M;
  if(a<0) return a+M;
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
void mulup(int &a,int b){
  a=mul(a,b);
}
const int N=(int)2e5+7;
int n,k,dp[N],sub[N],tol[N];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  dp[0]=1;
  int st=0;
  for (int jump=k;jump<=n;jump++) {
    for(int i=st;i<=n;i++)sub[i]=dp[i];
    while(st<=n&&dp[st]==0)st++;
    for(int i=st;i+jump<=n;i++) {
      addup(dp[i+jump],dp[i]);
    }
    for(int i=st;i<=n;i++)addup(dp[i],-sub[i]);
    for(int i=st;i<=n;i++)addup(tol[i],dp[i]);
  }
  for(int i=1;i<=n;i++){
    cout<<tol[i]<<" ";
  }
  cout<<"\n";

}