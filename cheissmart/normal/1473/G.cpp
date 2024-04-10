#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << to_string(x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string to_string(vi v) {
	string s = "[";
	for(int i = 0; i < v.size(); i++) {
		if(i) s += ", ";
		s += to_string(v[i]);
	}
	s += "]";
	return s;
}

const int INF = 1e9 + 7, M = 998244353, G = 3, N = 2e5 + 7;

int qpow(int a, int b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int inv(int a) {
	return qpow(a, M - 2);
}

void NTT(vi& a, int k, bool inverse) {
	vi pos(1 << k);
	for(int i = 1; i < (1 << k); i++)
		pos[i] = (pos[i >> 1] >> 1) | ((i & 1) << (k - 1));
	for(int i = 0; i < (1 << k); i++) if(pos[i] < i)
		swap(a[i], a[pos[i]]);
	for(int len = 2; len <= (1 << k); len *= 2) {
		int omega = qpow(G, (M - 1) / len);
		if(inverse) omega = inv(omega);
		for(int i = 0; i < (1 << k); i += len) {
			int cur = 1;
			for(int j = i; j < i + len / 2; j++) {
				int l = a[j], r = (ll) a[j + len / 2] * cur % M;
				a[j] = (l + r) % M;
				a[j + len / 2] = (l - r + M) % M;
				cur = (ll) cur * omega % M;
			}
		}
	}
}

vi mul(vi a, vi b) {
	int n = a.size(), m = b.size();
	vi c(n + m - 1);
	int k = __lg(n + m - 1) + 1, len = 1 << k;
	a.resize(len), b.resize(len);
	NTT(a, k, false), NTT(b, k, false);
	for(int i = 0; i < len; i++)
		a[i] = (ll) a[i] * b[i] % M;
	NTT(a, k, true);
	int INV = inv(len);
	for(int i = 0; i < n + m - 1; i++)
		c[i] = (ll) a[i] * INV % M;
	return c;
}

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

int f[N], _inv[N], fi[N];

int C(int n, int k) {
	if(k < 0 || k > n) return 0;
	return (ll) f[n] * fi[k] % M * fi[n - k] % M;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	f[0] = 1;
	for(int i = 1; i < N; i++)
		f[i] = (ll) f[i - 1] * i % M;
	_inv[1] = 1;
	for(int i = 2; i < N; i++)
		_inv[i] = M - (ll) M / i * _inv[M % i] % M;
	fi[0] = 1;
	for(int i = 1; i < N; i++)
		fi[i] = (ll) fi[i - 1] * _inv[i] % M;

	int n;
	cin >> n;
	vi old({1});
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int m = old.size(), mm = m + a - b;
		int lb = b - m + 1, rb = a + m - 1;
		vi aux;
		for(int j = lb; j <= rb; j++)
			aux.PB(C(a + b, j));
		vi res = mul(old, aux);
		vi nw(mm);
		for(int j = 0; j < mm; j++)
			nw[j] = res[j + m - 1];
		swap(old, nw);
	}

	int ans = 0;
	for(int i = 0; i < old.size(); i++)
		add(ans, old[i]);
	cout << ans << '\n';

}