#include <bits/stdc++.h>

using namespace std;

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

const int inv2=dv(1,2);

int gauss(int l){
  return mul(inv2,mul(l,l+1));
}

int gauss(int l,int r){
  return add(gauss(r),-gauss(l-1));
}

const int N=(int)1e6+7;
int n,cnt[N],fact[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  fact[0]=1;
  for (int i=1;i<N;i++)fact[i]=mul(fact[i-1],i);

  cin>>n;
  int l=1,r=0;
  for (int i=1;i<=n;i++){
    int len;
    cin>>len;
    cnt[len]++;
    r=add(r,len);
  }
  int sum=0,total=1;
  for (int i=N-1;i>=1;i--){
    if (cnt[i]==0)continue;
    int coef=(i-1);

    addup(sum,mul(gauss(l,add(l,cnt[i]-1)),add(0,-coef)));
    addup(sum,mul(gauss(add(r,-cnt[i]+1),r),coef));

    l=add(l,cnt[i]);
    r=add(r,-cnt[i]);

    if (i==1) {
      total=mul(total,fact[cnt[i]]);
    }else{
      total=mul(total,fact[cnt[i]]);
      total=mul(total,fact[cnt[i]]);

    }

    if (i-2>=1){
      addup(cnt[i-2],cnt[i]);
    }
  }

  cout<<sum<<" "<<total<<"\n";





  return 0;
}