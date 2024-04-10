#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 301010
int n;
int p[maxn];

int findp(int u) { return p[u] = u == p[u] ? u : findp(p[u]); }
void join(int u, int v) {
  p[findp(u)] = findp(v);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) p[i] = i;
  cout << "1 ";
  rep1(i, n) {
    int u; cin >> u;
    join(u, u - 1);
    int tm = n - findp(n);
    // clog << i << ' ' << tm << ' ' << findp(n) << endl;
    cout << (i - tm + 1) << ' ';
  }
  
  return 0;
}