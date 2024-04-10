#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(a) a.size()
#define all(a) begin(a), end(a)
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

vector<int> multiconv(vector<vector<int>>& polys) {
  int i=0;
  vd a, b;
  vector<int> nxt;
  for (; polys.size()-i > 1;) {
    a.clear(); b.clear();
    for (int j=0; j<polys[i].size(); ++j) {
      a.push_back(polys[i][j]);
    }
    ++i;
    for (int j=0; j<polys[i].size(); ++j) {
      b.push_back(polys[i][j]);
    }
    ++i;
    vd res = conv(a, b);
    nxt.clear();
    for (int j=0; j<res.size(); ++j) {
      nxt.push_back(((ll) (res[j]+.5))%1009);
    }
    polys.push_back(nxt);
  }
  return polys.back();
}

int amt[200200];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i=1; i<=n; ++i) {
    int a;
    cin >> a;
    ++amt[a];
  }
  vector<vector<int>> polys;
  for (int i=1; i<=m; ++i) {
    vector<int> q;
    for (int j=0; j<=amt[i]; ++j) {
      q.push_back(1);
    }
    polys.push_back(q);
  }
  vector<int> res = multiconv(polys);
  cout << res[k] << "\n";
  return 0;
}