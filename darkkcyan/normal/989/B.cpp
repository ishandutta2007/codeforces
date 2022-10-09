#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, p; cin >> n >> p;
  string s; cin >> s;
  queue<int> qu;
  rep(i, n) if (s[i] != '.') qu.push(i);
  int cnt = 0;
  for (; len(qu); qu.pop()) {
    int u = qu.front();
    int vv[] = {-1, 1};
    rep(i, 2) {
      int v = u + vv[i] * p;
      if (v < 0 || v >= len(s)) continue;
      if (s[v] == '.') {
        s[v] = !(s[u] - '0') + '0';
        qu.push(v);
      } else if (s[v] == s[u]) {
        //clog << u << ' ' << v << endl;
        ++cnt;
      }
    }
  }
  rep(i, n) {
    if (s[i] != '.') continue;
    if (i - p >= 0) s[i] = !(s[i - p] - '0') + '0';
    else s[i] = '1';
  }
  if ((n - p) * 2 == cnt) {
    cout << "No";
    //clog << s << endl;
    exit(0);
  }
  cout << s;

  return 0;
}