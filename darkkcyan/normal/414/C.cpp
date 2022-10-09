#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 22
#define ll pair<llong, llong>
int n;
int a[1 << maxn];

llong merge(int a[], int l, int r) {
  int mid = (r + l) / 2;
  vector<int> u(a + l, a + mid + 1), v(a + mid + 1, a + r + 1);
  llong inv = 0;
  int i = l, x = 0, y = 0;
  while (x < len(u) and y < len(v)) {
    if (u[x] <= v[y]) {
      a[i++] = u[x++];
      inv += y;
    } else {
      a[i++] = v[y++];
    }
  }
  while (x < len(u)) a[i++] = u[x++], inv += y;
  while (y < len(v)) a[i++] = v[y++];
  return inv;
}

llong pval[maxn], rpval[maxn];
int b[1 << maxn];
void process(int d, int l, int r) {
  if (l == r) return;
  int mid = (r + l) / 2;
  process(d + 1, l, mid); process(d + 1, mid + 1, r);
  int len = r - l + 1;
  memcpy(b, a + l, len * sizeof(a[0]));
  pval[d] += merge(a, l, r);
  len /= 2;
  memcpy(a + l + len, b, len * sizeof(b[0]));
  memcpy(a + l, b + len, len * sizeof(b[0]));
  // clog << "rev " << endl;
  // for (int i = l; i <= r; ++i) clog << a[i] << ' ';
  // clog << endl;
  rpval[d] += merge(a, l, r);
}

int rev[maxn] = {0};
llong cal(int d) {
  for (int i = d; i < maxn; ++i) rev[i] ^= 1;
  llong ans = 0;
  rep(i, maxn) {
    ans += rev[i] ? rpval[i] : pval[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, (1 << n)) cin >> a[i];
  process(0, 0, (1 << n) - 1);
  // rep(i, n + 1) clog << i << ' ' << pval[i] << ' ' << rpval[i] << endl;
  int m; cin >> m;
  while (m--) {
    int d; cin >> d;
    cout << cal(n - d) << '\n';
  }
  
  return 0;
}