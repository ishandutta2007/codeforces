#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 131072 + 7;
int n;
int a[N];
int cost[4 * N][26];
int f[N][26];
string s;

void solve(int v, int l, int r) {
  if (l == r) {
    for (int x = 0; x < 26; x++) {
      cost[v][x] = (a[l] != x);
    }
    return;
  }
  int m = (l + r) / 2;
  solve(2 * v, l, m);
  solve(2 * v + 1, m + 1, r);
  for (int x = 0; x < 26; x++) {
    cost[v][x] = N + 100;
    if (x + 1 < 26) {
      cost[v][x] = min(cost[v][x], (r - l + 1) / 2 - (f[m][x] - f[l - 1][x]) + cost[2 * v + 1][x + 1]);
      cost[v][x] = min(cost[v][x], (r - l + 1) / 2 - (f[r][x] - f[m][x]) + cost[2 * v][x + 1]);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      a[i] = s[i - 1] - 'a';
      for (int x = 0; x < 26; x++) {
        f[i][x] = f[i - 1][x];
      }
      f[i][a[i]]++;
    }
    solve(1, 1, n);
    cout << cost[1][0] << "\n";
  }
  return 0;
}