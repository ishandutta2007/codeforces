#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define ii pair<int, int>
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

int grun(int num, bool k) {
  if (num <= 1) return num;
  if (num & 1) return k ? num <= 3 : 0;
  int u = k ? grun(num / 2, k) : 0, v = grun(num - 1, k);
  rep(i, 3) if (i != u and i != v) return i;
  assert(false);
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int sx = 0;
  rep(i, n) {
    int u; cin >> u;
    sx ^= grun(u, k & 1);
  }
  if (sx) cout << "Kevin";
  else cout << "Nicky";

  return 0;
}