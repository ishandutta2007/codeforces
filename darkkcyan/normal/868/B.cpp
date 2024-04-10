#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int mark[200];
int p[200];
int findp(int u) { return p[u] = u == p[u] ? u : findp(p[u]); }
void join(int u, int v) { p[findp(u)] = findp(v); }

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int h, m, s, t1, t2; cin >> h >> m >> s >> t1 >> t2;
  h %= 12; t1 %= 12; t2 %= 12;
  t1 *= 5;
  t2 *= 5;
  h *= 5;

  mark[s * 2] = 1;
  if (s) mark[m * 2 + 1] = 1;
  else mark[m * 2] = 1;
  if (m or s) mark[h * 2 + 1] = 1;
  else mark[h * 2] = 1;

  rep(i, 120) p[i] = i;
  rep(i, 120 - 1) {
    if (mark[i] or mark[i + 1]) continue;
    join(i, i + 1);
  }
  if (!mark[0] and !mark[119]) join(0, 119);

  if (findp(t1 * 2) == findp(t2 * 2)) cout << "YES";
  else cout << "NO";
  
  return 0;
}