#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<array<int, 2>> nxt = {{-1, -1}};
  vector<int> sz = {0};

  vector<map<int, array<int, 2>>> cnt(31);
  vector<array<long long, 2>> invs(31);
  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int node = 0;
    for (int bit = 30; bit >= 0; --bit) {
      int val = !!(a[i] & (1 << bit));
      int go = nxt[node][val];
      int oth = nxt[node][!val];

      if (go == -1) {
        go = nxt.size();
        nxt.push_back(array<int, 2>({-1, -1}));
        sz.push_back(0);
        nxt[node][val] = go;
      }

      sz[go] += 1;
      int add = oth == -1 ? 0 : sz[oth];

      if (val == 1) {
        invs[bit][1] += add;
      } else {
        invs[bit][0] += add;
      }
      node = go;
    }
  }

  int x = 0;
  long long total = 0;
  for (int bit = 30; bit >= 0; --bit) {
    if (invs[bit][0] <= invs[bit][1]) {
      total += invs[bit][0];
    } else {
      total += invs[bit][1];
      x |= (1 << bit);
    }
  }
  cout << total << " " << x << endl;

  return 0;
}