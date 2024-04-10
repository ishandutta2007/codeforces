#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
const int FACTN=300000+7;
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
int getCOMB(int n,int k){
  return mul(fact[n],mul(ifact[k],ifact[n-k]));
}

const int N=(int)1e6+7;
int dp[N]; /// dp[diam size] given that each vertex has at most two kids
int pref[N];
int one[N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int inv2=dv(1,2);
  int inv6=dv(1,6);

  int nwant;
  cin>>nwant;

  if (nwant==1) {
    cout << "5\n";
    exit(0);
  }

  dp[0]=1;
  pref[0]=1;
  for (int n=1;n<=nwant;n++) {
    /// dp[n]
    dp[n]=0;
    addup(dp[n],dp[n-1]);
    addup(dp[n],mul(dp[n-1],dp[n-1]+1,inv2));
    if(n-2>=0) {
      addup(dp[n],mul(dp[n-1],pref[n-2]));
    }else{
      for (int oth=0;oth<=n-2;oth++) { /// optimize!!!!!!!!!!!!!!!!!!!!!!!
        addup(dp[n],mul(dp[n-1],dp[oth]));
      }
    }
    pref[n]=add(pref[n-1],dp[n]);
  }
  for (int n=1;n<=nwant;n++) {
    one[n]=add(dp[n],-dp[n-1]);
  }
  int print_sol=0;
  addup(print_sol,dp[nwant]);
  addup(print_sol,mul(dp[nwant-1],pref[nwant-2],pref[nwant-2]+1,inv2));
  addup(print_sol,mul(dp[nwant-1],dp[nwant-1]+1,pref[nwant-2],inv2));
  addup(print_sol,mul(dp[nwant-1],dp[nwant-1]+1,dp[nwant-1]+2,inv6));
  mulup(print_sol,2);
  addup(print_sol,-1);
 // print_sol=0;
  for (int i=0;i<=nwant-1;i++) {
    addup(print_sol,mul(add(dp[i],-1),one[nwant-1-i]));
  }
  cout<<print_sol<<"\n";
  exit(0);
}