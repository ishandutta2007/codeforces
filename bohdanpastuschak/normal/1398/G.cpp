#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace FFT
{
	struct complex
	{
		double x, y;
		complex() { x = y = 0; }
		complex(double _x, double _y) : x(_x), y(_y) { }
	};

	inline complex operator+(complex a, complex b) { return complex(a.x + b.x, a.y + b.y); }
	inline complex operator-(complex a, complex b) { return complex(a.x - b.x, a.y - b.y); }
	inline complex operator*(complex a, complex b) { return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline complex conj(complex a) { return complex(a.x, -a.y); }

	int base = 1;
	vector<complex> roots = { { 0, 0 },{ 1, 0 } };
	vector<int> rev = { 0, 1 };

	void ensure_base(int nbase)
	{
		if (nbase <= base)
			return;

		rev.resize(1 << nbase);
		FOR(i, 0, 1 << nbase)
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

		roots.resize(1 << nbase);
		while (base < nbase)
		{
			double angle = 2.0 * PI / (1 << (base + 1));
			FOR(i, 1 << (base - 1), 1 << base)
			{
				roots[i << 1] = roots[i];
				double angle_i = angle * (2 * i + 1 - (1 << base));
				roots[(i << 1) + 1] = complex(cos(angle_i), sin(angle_i));
			}

			base++;
		}
	}

	void fft(vector<complex>& a, int n = -1)
	{
		if (n == -1)
			n = a.size();

		int zeros = __builtin_ctz(n);
		ensure_base(zeros);

		int shift = base - zeros;
		FOR(i, 0, n)
			if (i < (rev[i] >> shift))
				swap(a[i], a[rev[i] >> shift]);

		for (int k = 1; k < n; k <<= 1)
		{
			for (int i = 0; i < n; i += 2 * k)
			{
				FOR(j, 0, k)
				{
					complex z = a[i + j + k] * roots[j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	vector<complex> fa, fb;

	void multiply(VI&a, VI&b, VI& res)
	{
		int need = SZ(a) + SZ(b) - 1;
		int nbase = 0;

		while ((1 << nbase) < need)
			nbase++;

		ensure_base(nbase);
		int sz = 1 << nbase;

		if (sz > SZ(fa))
			fa.resize(sz);

		FOR(i, 0, sz)
		{
			int x = (i < SZ(a) ? a[i] : 0);
			int y = (i < SZ(b) ? b[i] : 0);
			fa[i] = complex(x, y);
		}

		fft(fa, sz);
		complex r(0, -0.25 / sz);
		FOR(i, 0, (sz >> 1) + 1)
		{
			int j = (sz - i) & (sz - 1);
			complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
			if (i != j)
				fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;

			fa[i] = z;
		}

		fft(fa, sz);
		res.resize(need);
		FOR(i, 0, need)
			if (fa[i].x > 0)
				res[i] = fa[i].x + 0.5;
			else
				res[i] = fa[i].x - 0.5;
	}
};


const int N = 1 << 18;
int n, x, y;
int a[N];
int ans[N + N];
bool is[N];

void roby_fft(){
	//FOR(i, 0, n + 1) FOR(j, 0, i) is[a[i] - a[j]] = 1;
	VI A(N + N, 0), B(N + N, 0), C;
	FOR(i, 0, n + 1){
		A[a[i]] = 1;
		B[N - a[i]] = 1;
	}
	
	FFT::multiply(A, B, C);
	FOR(i, N, N + N) if (i < SZ(C) && C[i]) {
		is[i - N] = 1;
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	FILL(ans, -1);
	cin >> n >> x >> y;
	FOR(i, 0, n + 1) cin >> a[i];

	roby_fft();
	FOR(i, 1, N) if (is[i]){
		int tut = y + i;
		for(int j = tut; j < N + N; j += tut){
			setmax(ans[j], 2 * tut);
		}
	}	

	int q; cin >> q;
	while(q--){
		cin >> x;
		cout << ans[x / 2] << ' ';
	}
	cout << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}