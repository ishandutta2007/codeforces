#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 32;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll cnt[N];
ll amt[N];
ll cur;
int n;

ll get_small(int x) {
  ll small = 0;
  for (int j=1; j<=x; ++j) {
    small += amt[j]*((1<<j)-1);
  }
  return small;
}

ll solve(int x, ll k, int d) {
  if (cur >= k) {
    return 0;
  }
  int i=x+1;
  for (i=x+1; i<n; ++i) {
    if (amt[i] != 0) {
      break;
    }
  }
  if (i==n) {
    ll small = get_small(x);
    if (small >= k-cur) {
      return k-cur;
    }
    return INF;
  }
  if ((1<<(i-x)) > k-cur) {
    ll small = get_small(x);
    amt[i]--;
    amt[i-1]+=2;
    if (i-1 <= x) {
      cur += 2;
    }
    ll res = solve(x, k, d+1);
    amt[i]++;
    amt[i-1]-=2;
    if (i-1 <= x) {
      cur -= 2;
    }
    res += 1;
    if (small >= k-cur) {
      res = min(res, k-cur);
    }
    return res;
  } else {
    ll take = min((k-cur)/(1LL<<(i-x)), amt[i]);
    amt[i] -= take;
    amt[x] += take*(1LL<<(i-x));
    cur += take*(1LL<<(i-x));
    ll res = solve(x, k, d+1);
    amt[i] += take;
    amt[x] -= take*(1LL<<(i-x));
    cur -= take*(1LL<<(i-x));
    return res + ((1LL<<(i-x))-1)*take;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i=0; i<n; ++i) {
    cin >> cnt[i];
  }
  for (int i=1; i<=q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, v;
      cin >> p >> v;
      cnt[p] = v;
    } else {
      ll x, k;
      cin >> x >> k;
      cur = 0;
      for (int j=0; j<n; ++j) {
        amt[j] = cnt[j];
        if (j <= x) {
          cur += amt[j];
        }
      }
      ll res = solve(x, k, 1);
      cout << (res < INF ? res : -1) << "\n";
    }
  }
  return 0;
}