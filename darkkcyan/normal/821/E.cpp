#include<bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )

#define mat vector<vector<llong> > 
#define rcnt(a) sz(a)
#define ccnt(a) sz(a[0])
#define rem ((llong) 1e9 + 7)

mat makemat(int n, int m) { return mat(n, vector<llong>(m)); }
mat iden(int n) {
  mat ans = makemat(n, n);
  rep(i, n) ans[i][i] = 1;
  return ans;
}

mat operator* (const mat& a, const mat& b) {
  assert(ccnt(a) == rcnt(b));
  mat ans = makemat(rcnt(a), ccnt(b));
  rep(i, rcnt(a))
  rep(f, ccnt(b))
  rep(k, ccnt(a))
    ans[i][f] = (ans[i][f] + a[i][k] * b[k][f] % rem) % rem;
  return ans;
}

mat ppow(mat b, llong m) {
  mat ans = iden(rcnt(b));
  for (; m > 0; m >>= 1) {
    if (m & 1) ans = ans * b;
    b = b * b;
  }
  return ans;
}

mat genmulmat(int n) {
  mat ans = makemat(n, n);
  rep(i, n) {
    ans[i][i] = 1;
    if (i > 0) ans[i][i - 1] = 1;
    if (i < n - 1) ans[i][i + 1] = 1;
  }
  return ans;
}

void fixsize(mat& a, int n) {
  assert(ccnt(a) == 1);
  a.resize(n, vector<llong>(1, 0));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; llong k;
  cin >> n >> k;
  mat ans = iden(1);
  rep(i, n) {
    llong a, b, c; cin >> a >> b >> c;
    ++c;
    b = min(b, k);
    fixsize(ans, c);
    ans = ppow(genmulmat(c), b - a) * ans;
  }

  cout << ans[0][0];

  return 0;
}