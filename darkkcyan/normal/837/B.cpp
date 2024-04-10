#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )

#define maxn 111

int n, m;
string a[maxn];

char all1(int r1, int c1, int r2, int c2) {
  char x = a[r1][c1];
  for (int i = r1; i < r2; ++i) 
    for (int f = c1; f < c2; ++f)
      if (a[i][f] != x) return '\0';
  return x;
}

#define quit(msg) cout << msg, exit(0);

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) {
    cin >> a[i];
    for (auto f: a[i]) if (f != 'R' and f != 'B' and f != 'G') quit("NO");
  }

  if (n % 3 == 0) {
    int cnt = 0, x = n / 3;
    set<char> se;
    for (int i = 0; i < 3; ++i) se.insert(all1(x * i, 0, x * (i + 1), m));
    if (se.size() == 3 and !se.count('\0')) quit("YES");
  }
  if (m % 3 == 0) {
    int cnt = 0, x = m / 3;
    set<char> se;
    for (int i = 0; i < 3; ++i) se.insert(all1(0, x * i, n, x * (i + 1)));
    if (se.size() == 3 and !se.count('\0')) quit("YES");
  }
  quit("NO");

  return 0;
}