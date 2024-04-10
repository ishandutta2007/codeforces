#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int F = 18;
const int N = 1<<F;
const int K = 11;
const int Q = F-K;
int n, m, q;

struct Fenwick {
  int t[(1<<K)+1];
  int tot;
  void add(int x, int v=1) {
    ++x;
    tot += v;
    for (; x<=(1<<K); x+=x&-x) {
      t[x] += v;
    }
  }
  int query(int x) {
    ++x;
    int ans = 0;
    for (; x; x-= x&-x) {
      ans += t[x];
    }
    return ans;
  }
};

Fenwick f[1<<Q];
int g[1<<K];
int at[N];
vector<tuple<int, int>> queries[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  vector<int> v;
  for (int i=1; i<=n; ++i) {
    int x;
    cin >> x;
    at[x]++;
  }
  cin >> q;
  for (int i=1; i<=q; ++i) {
    int l, r;
    cin >> l >> r;
    queries[l].push_back({l, i});
    queries[r+1].push_back({l, i});
  }
  for (int i=m; i>=1; --i) {
    int hi = i>>K;
    int lo = i - (hi<<K);
    if (at[i]%2) {
      g[lo]++;
      f[hi].add(lo);
    }
    for (auto& [off, idx] : queries[i]) {
      int z = 0;
      for (int j=0; j<(1<<K); ++j) {
        if (g[j]%2) {
          z ^= ((j^N)-off)&((1<<K)-1);
        }
      }

      for (int j=(1<<Q)-1; j>=0 && ((j+1)<<K) >= i; --j) {
        int under = f[j].query((off&((1<<K)-1))-1);
        int above = f[j].tot-under;
        if (under%2) {
          int x = j - (off>>K) - 1;
          z ^= x<<K;
        }
        if (above%2) {
          int x = j - (off>>K);
          z ^= x<<K;
        }
      }
      ans[idx] ^= z;
    }
  }

  for (int i=1; i<=q; ++i) {
    cout << (ans[i] ? 'A' : 'B') ;
  }
  cout << endl;

  return 0;
}