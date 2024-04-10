#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int inf = 1e9 + 7;
const ll linf  = 1ll * inf * inf;
const int N = 500000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

class FFT {
	struct cp {
		double x, y;
		cp(const double &_x = 0, const double &_y = 0) : x(_x), y(_y) {}
		cp operator+(const cp &a) { return cp(a.x + x, a.y + y); }
		cp operator-(const cp &a) { return cp(x - a.x, y - a.y); }
		cp operator*(const cp &a) { return cp(x * a.x - y * a.y, x * a.y + y * a.x); }
		cp operator!() { return cp(x, -y); }
	};
	
	const double PI = acos(-1);
	static const int MAXN = (1 << 18) + 7;
	static const int BIT_SHIFT = 15;
	static const int BIT_MASK = (1 << BIT_SHIFT) - 1;
	
	cp w[MAXN];
	int bitrev[MAXN];
	
	void fft(cp *a, const int &n)
	{
		for (int i = 0; i < n; ++i)
			if (i < bitrev[i])
				swap(a[i], a[bitrev[i]]);
		for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
			for (int j = 0; j < n; j += i)
			{
				cp *l = a + j, *r = a + j + (i >> 1), *p = w;
				for (int k = 0; k<i>> 1; ++k)
				{
					cp tmp = *r * *p;
					*r = *l - tmp, *l = *l + tmp;
					++l, ++r, p += lyc;
				}
			}
	}
	
	inline void init(int N, int L) {
		for (int i = 0; i < N; ++i)
			bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
		for (int i = 0; i < N; ++i)
			w[i] = cp(cos(2 * PI * i / N), sin(2 * PI * i / N));
	}
	
public:
	inline vector<int> multiply(const vector<int> &x, const vector<int> &y, int mod) {
		static cp a[MAXN], b[MAXN];
		static cp dfta[MAXN], dftb[MAXN], dftc[MAXN], dftd[MAXN];
		int L = 0;
		while ((1 << L) < x.size() + y.size() - 1) ++L;
		int N = 1 << L;
		init(N, L);
		for (int i = 0; i < N; ++i) a[i] = b[i] = cp(0, 0);
		for (int i = 0; i < x.size(); ++i) a[i] = cp(x[i] & BIT_MASK, x[i] >> BIT_SHIFT);
		for (int i = 0; i < y.size(); ++i) b[i] = cp(y[i] & BIT_MASK, y[i] >> BIT_SHIFT);
		fft(a, N); fft(b, N);
		for (int i = 0; i < N; ++i) {
			int j = (N - i) & (N - 1);
			static cp da, db, dc, dd;
			da = (a[i] + !a[j]) * cp(0.5, 0);
			db = (a[i] - !a[j]) * cp(0, -0.5);
			dc = (b[i] + !b[j]) * cp(0.5, 0);
			dd = (b[i] - !b[j]) * cp(0, -0.5);
			dfta[j] = da * dc;
			dftb[j] = da * dd;
			dftc[j] = db * dc;
			dftd[j] = db * dd;
		}
		for (int i = 0; i < N; ++i) a[i] = dfta[i] + dftb[i] * cp(0, 1);
		for (int i = 0; i < N; ++i) b[i] = dftc[i] + dftd[i] * cp(0, 1);
		fft(a, N); fft(b, N);
		vector<int> z(x.size() + y.size() - 1);
		for (int i = 0; i < x.size() + y.size() - 1; ++i) {
			int da = (long long)(a[i].x / N + 0.5) % mod;
			int db = (long long)(a[i].y / N + 0.5) % mod;
			int dc = (long long)(b[i].x / N + 0.5) % mod;
			int dd = (long long)(b[i].y / N + 0.5) % mod;
			z[i] = (da + ((long long)(db + dc) << BIT_SHIFT) + ((long long)dd << (2 * BIT_SHIFT))) % mod;
		}
		return z;
	}
} fft;

int n, m, k;
int cnt[N];

void solve() {
	cin >> n >> m >> k;
	rep(i, 0, n) {
		int u;
		scanf("%d", &u); cnt[u - 1]++;
	}
	
	priority_queue<pair<int, vi>> heap;
	rep(i, 0, m) {
		if (cnt[i] > 0) {
			vi tmp(min(k, cnt[i]) + 1, 1);
			heap.push({-tmp.size(), tmp});
		}
	}
	
	while (heap.size() > 1) {
		vector<int> a = heap.top().second; heap.pop();
		vector<int> b = heap.top().second; heap.pop();
		
		vector<int> f = fft.multiply(a, b, 1009);
		while (f.size() > k + 1) f.pop_back();
		heap.push({-sz(f), f});
	}
	
	vector<int> f = heap.top().second;
	if (f.size() <= k) puts("0");
	else cout << f[k] << '\n';
	
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin);
	//    freopen("out.txt", "w", stdout);
#endif
	int Test = 1;
	if (multipleTest) {
		cin >> Test;
	}
	for(int i = 0; i < Test; ++i) {
		//		printf("Case #%d: ", i + 1);
		solve();
	}
#ifdef _LOCAL_
	cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}