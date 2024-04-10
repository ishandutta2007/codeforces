#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int A = 62;
const int B = 15;
const int ITER = 50;
const int M = 200'200;

int n, m, p;
ll a[M];
int cnt[1 << B];

int bit(ll mask, int i) {
  return (mask >> i) & 1;
}

void conv() {
  for (int i = 0; i < B; ++i)
    for (int mask = 0; mask < (1 << B); ++mask)
      if (bit(mask, i))
        cnt[mask ^ (1 << i)] += cnt[mask];
}

int main() {
  cin >> n >> m >> p;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ll cur = 0;
    for (int j = 0; j < m; ++j)
      if (s[j] == '1') {
        cur |= 1ll << j;
      }
    a[i] = cur;
  }

  set<int> best = {};
  mt19937 rnd(14881488);

  for (int _ = 0; _ < ITER; ++_) {
    int at = rnd() % n;

    vector<int> bs;
    for (int j = 0; j < m; ++j) {
      if (bit(a[at], j))
        bs.push_back(j);
    }

    fill(cnt, cnt + (1 << B), 0);

    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < (int) bs.size(); ++j) {
        if (bit(a[i], bs[j]))
          cur |= 1 << j;
      }
      cnt[cur]++;
    }

    conv();

    for (int mask = 0; mask < (1 << B); ++mask)
      if (cnt[mask] >= (n + 1) / 2 && __builtin_popcount(mask) > best.size()) {
        best = {};
        for (int j = 0; j < B; ++j)
          if (bit(mask, j))
            best.insert(bs[j]);
      }
  };

  for (int i = 0; i < m; ++i) {
    if (best.count(i))
      cout << "1";
    else
      cout << "0";
  }
  cout << "\n";
}