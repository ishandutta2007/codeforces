/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

const int N = 5010;
const int MOD = 1e9 + 7;
void add( int &a, int b ) { if ((a += b) >= MOD) a -= MOD; }

int f[N][N], lcp[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, sum = 0;
  string s;
  cin >> n >> s;
  f[0][0] = 1;
  fornd(i, n)
    fornd(j, n)
      lcp[i][j] = (s[i] == s[j] ? 1 + lcp[i + 1][j + 1] : 0);
  forn(l, n)
    for (int r = l; r <= n; r++)
      if (r == n)
        add(sum, f[l][r]);
      else if (f[l][r]) {
        add(f[l][r + 1], f[l][r]);
        if (r > l  && r + (r - l) <= n && s[r] != '0') {
          int m = lcp[l][r];
          bool sh = (m >= r - l || s[l + m] > s[r + m]);
          add(f[r][r + (r - l) + sh], f[l][r]);
        }
      }
  cout << sum << endl;
}