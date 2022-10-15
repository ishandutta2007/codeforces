#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = (int) 2e5 + 7;
int n, k, cnt[N];
vector<int> d[N];

int get(int l, int r, int val) {
  return r / val - (l - 1) / val;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 2; i <= 2 * n; i++) {
    if (d[i].empty()) {
      for (int j = i; j <= 2 * n; j += i) {
        d[j].push_back(i);
      }
    }
  }
  for (int g = 1; g <= n - 1; g++) {
    for (int s = g; s <= 2 * (n - 1); s += g) {
      int val = s / g, ret = 0, l = max(1, (s - n + g) / g), r = (min(n, s) - 1) / g;
      vector<int> v = d[val];
      int sz = (int) v.size();
      for (int mask = 0; mask < (1 << sz); mask++) {
        int cnt = 0, num = 1;
        for (int bit = 0; bit < sz; bit++) {
          if (mask & (1 << bit)) {
            num *= v[bit];
            cnt++;
          }
        }
        if (cnt & 1) {
          ret -= get(l, r, num);
        } else {
          ret += get(l, r, num);
        }
      }
      cnt[max(s - n, g)] = add(cnt[max(s - n, g)], ret);
    }
  }
  int invk = dv(1, k), val = 1, ret = 0;
  for (int i = 1; i <= n; i++) {
    val = mul(val, invk);
    ret = add(ret, mul(cnt[n - i], val));
  }
  cout << ret << "\n";
}