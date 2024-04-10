#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m, k;

struct Seg {
  int l, r;
  bool operator< (const Seg& o) const {
    return l+r < o.l+o.r;
  }
};

const int N = 2020;
int pr[N], su[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  vector<Seg> segs;
  for (int i=0; i<m; ++i) {
    int l, r;
    cin >> l >> r;
    segs.push_back({l-1, r});
  }
  sort(segs.begin(), segs.end());
  for (int i=0; i<=n-k; ++i) { // location of left editorialist
    int res = 0;
    for (int j=0; j<m; ++j) {
      res += max(0, min(segs[j].r, i+k) - max(i, segs[j].l));
      pr[j] = max(pr[j], res);
    }
  }
  for (int i=0; i<=n-k; ++i) {
    int res = 0;
    for (int j=m-1; j>=0; --j) {
      res += max(0, min(segs[j].r, i+k) - max(i, segs[j].l));
      su[j] = max(su[j], res);
    }
  }
  int ans = max(su[0], pr[m-1]);
  for (int i=0; i<m-1; ++i) {
    ans = max(ans, pr[i]+su[i+1]);
  }
  cout << ans << "\n";

  return 0;
}