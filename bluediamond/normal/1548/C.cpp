#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=(int) 1e9+7;
const int FACTN=(int)4e6+7;
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
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
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
int fact[FACTN],ifact[FACTN];
void computeFACT(){
  fact[0]=1;
  for(int i=1;i<FACTN;i++)fact[i]=mul(fact[i-1],i);
  ifact[FACTN-1]=dv(1,fact[FACTN-1]);
  for(int i=FACTN-2;i>=0;i--)ifact[i]=mul(ifact[i+1],i+1);
}
int comb(int n,int k){
  if (k>n){
    return 0;
  }
  assert(0<=k&&k<=n&&n<FACTN);
  return mul(fact[n],mul(ifact[k],ifact[n-k]));
}
const int N=FACTN;
int n;
int q;
int dp[N][3];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  computeFACT();

  cin>>n>>q;
  dp[0][0]=dp[0][1]=dp[0][2]=n+1;
  for (int x=1;x<=3*n;x++) {
    dp[x][1]=dv(add(comb(3*n+3,x+1),-dp[x-1][1],dp[x-1][0]),3);
    dp[x][2]=add(dp[x][1],dp[x-1][1]);
    dp[x][0]=add(comb(3*n+3,x+1),-dp[x][1],-dp[x][2]);
  }
  for (int iq=1;iq<=q;iq++) {
    int x;
    cin>>x;
    cout<<dp[x][0]<<"\n";
  }

  return 0;
}
/**

**/