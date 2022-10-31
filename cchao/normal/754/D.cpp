#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

template <typename T>
using hyperset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 300010;
hyperset<PII> s;
PII a[maxn];
vector<PII> v;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  REPE(i, 1, n) {
    int l, r;
    scanf("%d%d", &l, &r);
    r++;
    a[i] = {l, r};
    v.EB(l, i);
    v.EB(r, -i);
  }
  sort(ALL(v));
  int large = 0;
  int chz = 0;
  for (auto &x : v) {
    if (x.S > 0) s.insert(x);
    else {
      int idx = abs(x.S);
      PII rm = {a[idx].F, idx};
      if (s.size() >= k) {
        auto y = *s.find_by_order(k - 1);
        int lb = y.F;
        if (x.F - y.F > large) {
          large = x.F - y.F;
          chz = x.F;
        }
      }
      s.erase(rm);
    }
  }
  printf("%d\n", large);
  if (large == 0) {
    REPE(i, 1, k) printf("%d%c", i, " \n"[i == k]);
    return 0;
  }
  vector<PII> w;
  REPE(i, 1, n) {
    if (a[i].S >= chz && a[i].F <= chz)
      w.EB(a[i].F, i);
  }
  sort(ALL(w));
  REP(i, k)
    printf("%d%c", w[i].S, " \n"[i == k - 1]);

  return 0;
}