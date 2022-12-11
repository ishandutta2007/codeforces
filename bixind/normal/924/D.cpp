#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 998244353;

struct frac {
  ll num, denom;
  int i;
  bool operator<(const frac& f) const {
    return num * f.denom < f.num * denom;
  }

  bool operator==(const frac& f) const {
    return num * f.denom == f.num * denom;
  }
};

bool cmp(const pair<frac, frac>& a, const pair<frac, frac>& b) {
  if (a.first == b.first) {
    return b.second < a.second;
  }
  return a.first < b.first;
}

ll T[100100];

void add(int p) {
  for (int i = p; i < 100100; i |= i + 1)
    T[i] += 1;
}

ll sum(int p) {
  ll ans = 0;
  for (int i = p; i >= 0; i = (i & (i + 1)) - 1)
    ans += T[i];
  return ans;
}

void solve() {
  int n, w;
  cin >> n >> w;
  vector<pair<frac, frac> > pl;
  vector<frac> srt;
  map<frac, int> pos;
  for (int i = 0; i < n; ++i) {
    ll x, v;
    cin >> x >> v;
    frac f, f2;
    f.num = llabs(-x);
    f.denom = llabs(v - w);
    f.i = i;
    f2.num = llabs(-x);
    f2.denom = llabs(v + w);
    f2.i = i;
    pl.push_back({f, f2});
    srt.push_back(f2);
//    cout << (ld) f.num / f.denom << endl;
  }
  sort(srt.begin(), srt.end());
  long cnt = unique(srt.begin(), srt.end()) - srt.begin();
  reverse(srt.begin(), srt.begin() + cnt);
  for (int i = 0; i < cnt; ++i) {
    pos[srt[i]] = i;
  }
  ll ans = 0;
  sort(pl.begin(), pl.end(), cmp);
  for (int i = 0; i < n; ++i) {
//    cout << pl[i].first.i << ' ';
    int p = pos[pl[i].second];
    ans += sum(p);
    add(p);
//    cout << ans << endl;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();

  return 0;
}