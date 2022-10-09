#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n;)
#define sz(v) ((int)v.size())

#define maxn 1010101
int n, a;
int cnt[maxn] = {0};
set<ii> se;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> a;
  rep(i, maxn) se.insert({0, i});
  se.erase({0, a});
  se.erase({0, 0});
  rep(i, n) {
    int x; cin >> x;
    if (se.count({cnt[x], x})) {
      se.erase({cnt[x], x});
      se.insert({cnt[x] + 1, x});
    }
    ++cnt[x];
    if (x != a) continue;
    while (sz(se) and se.begin()->xx < cnt[a]) {
      se.erase(se.begin());
    }
  }
  if (!sz(se)) cout << -1;
  else cout << se.rbegin()->yy;
  return 0;
}