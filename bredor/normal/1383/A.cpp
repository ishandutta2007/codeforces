#include <bits/stdc++.h>

using namespace std;

const int M = 22;

int p[M];

void ini() {
  iota(p, p + M, 0);
}

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
  x = get(x);
  y = get(y);
  p[x] = y;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    set<pair<char, char>> res;

    ini();

    bool horosho = true;

    for (int i = 0; i < n; ++i)
      if (s[i] != t[i]) {
        if (s[i] > t[i]) {
          cout << "-1\n";
          horosho = false;
          break;
        } else {
          res.emplace(s[i], t[i]);
          uni(s[i] - 'a', t[i] - 'a');
        }
      }


    if (!horosho)
      continue;

    int ans = 20;
    for (int i = 0; i < 20; ++i)
      if (get(i) == i)
        --ans;

    cout << ans << "\n";
  }

}