%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int mod = 998244353;
const int N = 100005;
int a[N], cnt[15];
int n;
 
void add(ll &a, ll b) {
  a += b;
  if (a > mod) a -= mod;
}
ll sum(ll a, ll b) {
  add(a, b); return a;
}
ll mul(ll a, ll b) {
  return (ll)a * b % mod;
}
 
ll f(vector <int>& a, int l) {
  ll res = 0LL, p = 1LL;
  for (int i = 0; i < max((int)a.size(), l); i++) {
    if (i < l) p = mul(p, 10LL);
    if (i < (int)a.size()) {
      add(res, mul(a[i], p));
      p = mul(p, 10LL);
    }
  }
  return res;
}
 
ll f(int l, vector <int>& b) {
  ll res = 0LL, p = 1LL;
  for (int i = 0; i < max(l, (int)b.size()); i++) {
    if (i < (int)b.size()) {
      add(res, mul(b[i], p));
      p = mul(p, 10LL);
    }
    if (i < l) p = mul(p, 10LL);
  }
  return res;
}
 
int main() {
  scanf("%d", &n);
 
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    a[i] = x;
    int _len = 0, tmp = x;
    while (tmp > 0) {
      _len++; tmp /= 10;
    }
    cnt[_len]++;
  }
  
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector <int> d;
    int tmp = a[i];
    while (tmp > 0) {
      d.push_back(tmp % 10);
      tmp /= 10;
    }
    
    for (int l = 1; l < 11; l++) {
      int sum = f(d, l);
      add(ans, mul(sum, cnt[l]));
      
      sum = f(l, d);
      add(ans, mul(sum, cnt[l]));
    }
  }
  printf("%lld\n", ans);
  return 0;
}