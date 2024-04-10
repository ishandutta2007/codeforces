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

const int N=200000+7;
int dp[N][1<<3][1<<3];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  vector<int> digits;
  int n;
  {
    string s;
    cin>>s;
    n=(int)s.size();
    for(auto&ch:s){
      assert(ch=='0'||ch=='1');
      digits.push_back(ch-'0');
    }
  }

  dp[0][(1<<0)+(1<<1)+(1<<2)][0]=1;

  for (int iter=1;iter<=n;iter++) {
    int x=digits[iter-1];
    assert(0<=x||x<=1);
    for (int eq_mask=0;eq_mask<(1<<3);eq_mask++) {
      for (int respect=0;respect<(1<<3);respect++) {
        int coef=dp[iter-1][eq_mask][respect];
        if(coef==0) {
          continue;
        }
        for (int now=0;now<(1<<3);now++) {
          int a=!!(now&(1<<0));
          int b=!!(now&(1<<1));
          int c=!!(now&(1<<2));
          if ((eq_mask&(1<<0)) && a>x) continue;
          if ((eq_mask&(1<<1)) && b>x) continue;
          if ((eq_mask&(1<<2)) && c>x) continue;
          int new_eq_mask=eq_mask;
          if ((eq_mask&(1<<0))&&a!=x) new_eq_mask-=(1<<0);
          if ((eq_mask&(1<<1))&&b!=x) new_eq_mask-=(1<<1);
          if ((eq_mask&(1<<2))&&c!=x) new_eq_mask-=(1<<2);
          int new_respect=respect,mask=now;
          if (mask==(1<<1)+(1<<2)||mask==(1<<0)) new_respect|=(1<<0);
          if (mask==(1<<0)+(1<<2)||mask==(1<<1)) new_respect|=(1<<1);
          if (mask==(1<<0)+(1<<1)||mask==(1<<2)) new_respect|=(1<<2);
          addup(dp[iter][new_eq_mask][new_respect], coef);
        }
      }
    }
  }
  int sol=0;
  for (int em=0;em<(1<<3);em++) {
    addup(sol, dp[n][em][(1<<0)+(1<<1)+(1<<2)]);
  }
  cout<<sol<<"\n";
  return 0;

  for (int i=0;i<n;i++) {
    cout<<digits[i]<<" ";
  }
  cout<<"\n";


  return 0;
}
/**

cnt011 + cnt100 > 0
cnt101 + cnt010 > 0
cnt110 + cnt001 > 0

**/