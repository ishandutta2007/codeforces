#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int long long

const int N = (int) 2e5 + 7;
int n, a[N], s[2], ret, pre[2][N];
int f(int x, int l, int r) {if (l == 0) return pre[x][r]; return pre[x][r] - pre[x][l - 1];}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> a[i]; s[i % 2] += a[i];}
  for (int i = 0; i < n; i++) {pre[0][i] = pre[0][i - 1]; pre[1][i] = pre[1][i - 1]; pre[i % 2][i] += a[i];}
  for (int i = 0; i < n; i++) ret = max(ret, f((i + 1) % 2, i + 1, n - 1) + f(i % 2, 0, i - 1) + a[i]);
  cout << ret << "\n";
}