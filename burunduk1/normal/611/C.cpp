/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 503;

int h, w, q;
string s[N];
int is1[N][N], is2[N][N];
int cnt1[N][N], cnt2[N][N];
int s1[N][N], s2[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> h >> w;
  forn(i, h)
    cin >> s[i];
  forn(i, h)
    forn(j, w) {
      is1[i][j] = (s[i][j] == '.' && s[i + 1][j] == '.');
      is2[i][j] = (s[i][j] == '.' && s[i][j + 1] == '.');
    }
  forn(i, h)
    forn(j, w) {
      cnt1[i + 1][j + 1] = is1[i][j] + cnt1[i][j + 1] + cnt1[i + 1][j] - cnt1[i][j];
      cnt2[i + 1][j + 1] = is2[i][j] + cnt2[i][j + 1] + cnt2[i + 1][j] - cnt2[i][j];
    }
  forn(i, h)
    forn(j, w) {
      s1[i + 1][j] = s1[i][j] + is1[i][j];
      s2[i][j + 1] = s2[i][j] + is2[i][j];
    }

  cin >> q;
  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2, y1--, x1--, y2--, x2--;
    #define get(cnt) (cnt[y2][x2] - cnt[y1][x2] - cnt[y2][x1] + cnt[y1][x1])
    //printf("%d %d %d %d\n", get(cnt1) , get(cnt2) , (is1[y2][x2] - is1[y1][x2]) , (is2[y2][x2] - is2[y2][x1]));
    cout << get(cnt1) + get(cnt2) + (s1[y2][x2] - s1[y1][x2]) + (s2[y2][x2] - s2[y2][x1]) << "\n";
  }
}