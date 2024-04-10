#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353LL
#define N 100000
#define ll long long
#define G 3LL
#define vll vector<long long>
#define pb push_back

int n, A, B, bit;

ll fpow(ll x, int p) {
  ll ret = 1;
  while(p) {
    if(p&1) ret = ret*x%MOD;
    x = x*x%MOD;
    p >>= 1;
  }
  return ret;
}

void reverse(vll &s, int cnt) {
  int len = 1<<cnt;
  for(int i = 0; i < len; ++i) {
    int t = 0;
    for(int j = 0; j < cnt; ++j)
      if((i>>j)&1) t |= 1<<(cnt-1-j);
    if(i < t) swap(s[i], s[t]);
  }
}

void DNT(vll &s, int cnt, int flag) {
  reverse(s, cnt);
  int len = 1<<cnt;
  for(int l = 2; l <= len; l <<= 1) {
    int k = l>>1;
    ll t = fpow(G, (MOD-1)/l);
    if(flag) t = fpow(t, MOD-2);
    for(auto p = s.begin(); p != s.begin()+len; p += l) {
      ll w = 1;
      for(int i = 0; i < k; ++i) {
        ll x = p[i], y = p[i+k]*w%MOD;
        p[i] = (x+y)%MOD, p[i+k] = (x-y)%MOD;
        w = w*t%MOD;
      }
    }
  }
}

vll solve(int l, int r, int cnt) {
  int len = 1<<cnt, mid = l+r>>1;
  if(len == 1) {
    vll ret;
    if(l < n-1) ret.pb(l), ret.pb(1);
    else ret.pb(1), ret.pb(0);
    return ret;
  }
  vll a = solve(l, mid, cnt-1), b = solve(mid+1, r, cnt-1);
  int tlen = len<<1;
  a.resize(tlen), b.resize(tlen);
  DNT(a, cnt+1, 0), DNT(b, cnt+1, 0);
  for(int i = 0; i < tlen; ++i) a[i] = a[i]*b[i]%MOD;
  DNT(a, cnt+1, 1);
  a.resize(len+1);
  ll invlen = fpow(1LL*tlen, MOD-2);
  for(int i = 0; i < a.size(); ++i) a[i] = a[i]*invlen%MOD;
  return a;
}

int main() {
  scanf("%d%d%d", &n, &A, &B);
  if(!A || !B || A+B-2 > n) {
    printf("0\n");
    return 0;
  }
  while((1<<bit) < n) bit++; //ans = S(n-1,a+b-2)*C(a+b-2,b-1)
  vll f = solve(0, (1<<bit)-1, bit);
  ll C = 1;
  for(int i = A; i <= A+B-2; ++i) C = C*i%MOD;
  for(int i = 1; i <= B-1; ++i) C = C*fpow(i, MOD-2)%MOD;
  printf("%lld\n", (f[A+B-2]*C%MOD+MOD)%MOD);
  return 0;
}