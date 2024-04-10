#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 201010
int n;
llong a[maxn];

map<llong, set<int> > ma;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) {
    cin >> a[i];
    ma[a[i]].insert(i);
  }
  llong k = n;
  while (len(ma)) {
    auto i = ma.begin();
    while (len(i->yy) >= 2) {
      int u = *i->yy.begin();
      i->yy.erase(i->yy.begin());
      int v = *i->yy.begin();
      i->yy.erase(i->yy.begin());
      a[u] = LLONG_MAX;
      a[v] = 2 * i->xx;
      ma[2 * i->xx].insert(v);
      --k;
    }
    ma.erase(i);
  }

  cout << k << '\n';
  rep1(i, n) if (a[i] != LLONG_MAX) cout << a[i] << ' ';

  return 0;
}