#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const int M = (int)1e9+7;

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

void mulup(int &a,int b){
  a=mul(a,b);
}

int n,frq[100],suf[100];

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);


  cin>>n;
  for (int i=1;i<=n;i++){
    int x,cnt=0;
    cin>>x;
    while (x%2==0){
      x/=2;
      cnt++;
    }
    frq[cnt]++;
  }
  for (int i=80;i>=0;i--){
    suf[i]=suf[i+1]+frq[i];
  }

  int sol=1;
  mulup(sol,add(pw(2,frq[0]),-1));
  mulup(sol,pw(2,n-frq[0]));
  for (int small=1;small<100;small++){
    if(frq[small]<2)continue;
    int val=add(pw(2,frq[small]-1),-1);
    mulup(val,pw(2,suf[small+1]));
    addup(sol,val);
  }
  cout<<sol<<"\n";
  return 0;
}