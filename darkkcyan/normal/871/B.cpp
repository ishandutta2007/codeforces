#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 5010
int n;
ii xorans[maxn];

int ask(int u, int v) {
  cout << "? " << u % n<< ' ' << v % n << endl;
  int x; cin >> x;
  return x;
}

int p[maxn], b[maxn];
int lastpos;
bool assign(int i) {
  for (int i = 0; i < n; ++i) p[i] = b[i] = 1 << 20;
  p[i] = 0;
  rep(f, n) {
    int u = (i + f) % n, v = (i + f + 1) % n;
    if ((b[u] = xorans[u].xx ^ p[u]) >= n) return false;
    if ((p[v] = xorans[u].yy ^ b[u]) >= n) return false;
  }
  //clog << i << endl;
  //rep(f, n) clog << p[f] << ' '; clog << endl;
  //rep(f, n) clog << b[f] << ' '; clog << endl;
  rep(i, n) {
    if (p[b[i]] != i) {
      return false;
    }
  }
  lastpos = i;
  return true;
}

int main() {
  cin >> n;
  rep(i, n) {
    xorans[i].xx = ask(i, i);
    xorans[i].yy = ask(i + 1, i);
  }
  int ans = 0;
  rep(i, n) {
    ans += assign(i);
  }
  assign(lastpos);
  cout << '!' << '\n';
  cout << ans << '\n';
  rep(i, n) cout << p[i] << ' ';
  fflush(stdout);
  return 0;
}