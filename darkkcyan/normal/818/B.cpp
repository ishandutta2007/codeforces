#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n;)

#define maxn 200
int n, m;
int l[maxn], a[maxn], has[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  rep(i, m) cin >> l[i], --l[i];
  memset(a, -1, sizeof(a));
  memset(has, 0, sizeof(has));
  rep(i, m - 1) {
    if (a[l[i]] == -1) {
      a[l[i]] = (l[i + 1] + n - l[i]) % n;
      if (a[l[i]] == 0) a[l[i]] = n;
    } else if ((l[i] + a[l[i]]) % n != l[i + 1]) {
      cout << -1;
      exit(0);
    }
  }

  rep(i, n) {
    if (a[i] == -1) continue;
    if (has[a[i]]) {
      cout << -1;
      exit(0);
    }
    has[a[i]] = 1;
  }

  int t = 1;
  rep(i, n) if (a[i] == -1)
    for (; ; ++t) if (!has[t]) {
      has[t] = 1;
      a[i] = t;
      break;
    }

  rep(i, n) cout << a[i] << ' ' ;
  return 0;
}