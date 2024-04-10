#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n;)
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

#define maxn 201010
int n;
llong t;
int a[maxn];
llong p[maxn];

vector<int> b;
bool ok(int num) {
  b.clear();
  rep(i, n) if (a[i] >= num) b.push_back(i);
  if (len(b) < num) return false;
  sort(b.begin(), b.end(), [](int u, int v) { return p[u] < p[v];} );
  b.resize(num);
  llong tl = 0;
  for (auto i: b) {
    tl += p[i];
  }
  return tl <= t;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> t;
  rep(i, n) cin >> a[i] >> p[i];
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (ok(mid)) l = mid;
    else r = mid - 1;
  }
  assert(ok(l));
  cout << l << '\n';
  cout << l << '\n';
  for (auto i: b) {
    cout << i + 1 << ' ';
  }

  return 0;
}