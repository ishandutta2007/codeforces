#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )


#define maxn 10101
#define sqr(x) ((x) * (x))
int n, r;
llong x[maxn];
long double y[maxn];

long double gety(int u, int v) {
  if (abs(x[u] - x[v]) > 2 * r) return r;
  return y[u] + sqrt(sqr(r + r) - sqr(x[u] - x[v]));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> r;
  rep(i, n) {
    cin >> x[i];
    y[i] = r;
    rep(f, i) {
      y[i] = max(y[i], gety(f, i));
    }
    cout << fixed << setprecision(10) << y[i] << ' ';
  }
  
  return 0;
}