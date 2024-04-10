#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define len(x) ((int)x.size())

#define maxn 201010
int n;
int a[maxn], b[maxn], p[maxn];

int main() {
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) p[i] = i;

  sort(a, a + n);
  sort(p, p + n, [](int u, int v) { return b[u] > b[v]; });

  rep(i, n) b[p[i]] = a[i];
  rep(i, n) cout << b[i] << ' ';

  return 0;
}