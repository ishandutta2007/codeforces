#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 1010
int n, c, m;
int a[maxn];

int main() {
  cin >> n >> m >> c;
  memset(a, -1, sizeof(a));
  bool ok = 0;
  c /= 2;
  while (!ok) {
    int u; cin >> u;
    int ans = -1;
    if (u <= c) {
      rep(i, n) {
        if (a[i] == -1 or a[i] > u) {
          ans = i;
          break;
        }
      }
    } else {
      for (int i = n; i--; ) {
        if (a[i] == -1 or a[i] < u) {
          ans = i;
          break;
        }
      }
    }
    assert(ans != -1);
    a[ans] = u;
    cout << ans + 1 << endl;
    ok = true;
    rep(i, n) if (a[i] == -1) {
      ok = false;
      break;
    }
    //rep(i, n) clog << a[i] << ' ';
    //clog << endl;
  }

  return 0;
}