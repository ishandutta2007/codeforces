#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  multiset<int> a;

  rep(i, k) {
    int x; cin >> x;
    a.insert(x);
  }

  int c2 = 2 * n, c4 = n;
  while (c4 and *--a.end() >= 4) {
    int x = *--a.end();
    a.erase(--a.end());
    --c4;
    x -= 4;
    a.insert(x);
  }

  while (c2 and *--a.end() >= 2) {
    int x = *--a.end();
    a.erase(--a.end());
    --c2;
    x -= 2;
    a.insert(x);
  }

  while (c4 and *--a.end() >= 2) {
    int x = *--a.end();
    a.erase(--a.end());
    --c4; ++c2;
    x -= 2;
    a.insert(x);
  }

  int s = 0;
  for (auto i: a) s += i;
  c2 += 2 * c4;
  if (c2 >= s) cout << "YES";
  else cout << "NO";


  return 0;
}