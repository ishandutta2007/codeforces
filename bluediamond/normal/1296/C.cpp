#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int t, n, ls, rs;
string s;

pair<int, int> operator + (pair<int, int> a, char ch) {
  if (ch == 'L') a.first--;
  if (ch == 'R') a.first++;
  if (ch == 'U') a.second++;
  if (ch == 'D') a.second--;
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ls = -1;
    rs = (int) 1e9;
    map<pair<int, int>, int> last;
    pair<int, int> pts;
    last[{0, 0}] = 0;
    for (int i = 1; i <= n; i++) {
      pts = pts + s[i - 1];
      if (last.count(pts)) {
        int l = last[pts] + 1;
        int r = i;
        if (r - l < rs - ls) {
          ls = l;
          rs = r;
        }
      }
      last[pts] = i;
    }
    if (ls == -1) {
      cout << "-1\n";
    } else {
      cout << ls << " " << rs << "\n";
    }
  }
  return 0;
}