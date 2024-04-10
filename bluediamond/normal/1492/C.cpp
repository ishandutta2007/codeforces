#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int long long

const int N = (int) 2e5 + 7;
int n, m, mn[N], mx[N], ret = -(int) 1e18;
string s, t;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> s >> t;
  t = "#" + t + "#";
  int j = 1;
  for (int i = 0; i < n; i++) if (s[i] == t[j]) mn[j++] = i;
  j = m;
  for (int i = n - 1; i >= 0; i--) if (s[i] == t[j]) mx[j--] = i;
  for (int i = 1; i < m; i++) ret = max(ret, mx[i + 1] - mn[i]);
  cout << ret << "\n";
}