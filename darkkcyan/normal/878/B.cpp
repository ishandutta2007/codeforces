#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxlen 5010100

llong n, k, m;
struct st {
  deque<ii> a;
  llong rem;
  
  st& operator+=(st o) {
    rem += o.rem;
    while (1) {
      if (!len(a) or !len(o.a)) break;
      if (a.back().xx != o.a.front().xx) break;
      llong t = a.back().yy + o.a.front().yy;
      rem += t / k;
      t %= k;
      if (t) a.back().yy = t; else a.pop_back();
      o.a.pop_front();
    }
    while (len(a) > maxlen / 2) a.pop_back();
    while (len(o.a) > maxlen / 2) o.a.pop_front();
    while (len(o.a)) a.push_back(o.a.front()), o.a.pop_front();
    // for (auto i: a) clog << i.xx << ':' << i.yy << ' ';
    // clog << endl;
    return *this;
  }
};

st x, ans;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k >> m;
  rep(i, n) {
    int u; cin >> u;
    if (len(x.a) == 0 or x.a.back().xx != u) x.a.push_back({u, 0});
    ++x.a.back().yy;
    if (x.a.back().yy >= k) x.a.pop_back(), x.rem ++;
  }
  
  // for (auto i: x.a) clog << i.xx << ':' << i.yy << ' ';
  // clog << endl;
  
  for (int i = m; i > 0; i >>= 1) {
    if (i & 1) ans += x;
    x += x;
  }
  
  cout << n * m - ans.rem * k;
  
  return 0;
}