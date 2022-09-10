#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;

namespace FFT
{
	typedef complex<double> base;
	const int MAX = 1 << 20;
	base PW[MAX];
	bool initialized = false;
	
	void init()
	{
		initialized = true;
		double angle = 2.0 * PI / MAX;
		FOR(i, 0, MAX)
		{
			double ang = angle * i;
			PW[i] = base(cos(ang), sin(ang));
		}
	}
	
	void fft(vector<base>& a, bool invert)
	{
		int lg = 0;
		while((1 << lg) < SZ(a))
			++lg;
		
		FOR(i, 0, SZ(a))
		{
			int x = 0;
			
			FOR(j, 0, lg)
				x |= ((i >> j) & 1) << (lg - j - 1);
			
			if (i < x)
				swap(a[i], a[x]);
		}
		
		for(int len = 2; len <= SZ(a); len <<= 1)
		{
			int diff = MAX / len;
			if (invert) 
				diff = MAX - diff;
			
			for (int i = 0; i < SZ(a); i += len)
			{
				int pos = 0;
				FOR (j, 0, len >> 1)
				{
					base v = a[i + j];
					base u = a[i + j + (len >> 1)] * PW[pos];
	 
					a[i + j] = v + u;
					a[i + j + (len >> 1)] = v - u;
	 
					pos += diff;
					if (pos >= MAX) 
						pos -= MAX;
				}
			}
		}
		
		if (invert)
			FOR(i, 0, SZ(a))
				a[i] /= SZ(a);
	}

	VI mult(VI a, VI b)
	{
		if (!initialized)
			init();
		
		int n = 1;
		while(n < SZ(a) + SZ(b))
			n <<= 1;
		
		a.resize(n);
		b.resize(n);
		
		VI c(n, 0);
		
		vector<base> fa(ALL(a)), fb(ALL(b));
		fft(fa, 0);
		fft(fb, 0);
		
		FOR(i, 0, n)
			fa[i] *= fb[i];
		
		fft(fa, 1);
		
		FOR(i, 0, n)
			if (fa[i].real() > 0.5)
				c[i] = 1;
		
		return c;
	}
};

namespace FastFFT
{
	struct complex
	{
		double x, y;
		complex() { x = y = 0; }
		complex(double x, double y) : x(x), y(y) { }
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

	VI mult(VI a, VI b)
	{
		int need = a.size() + b.size() - 1;
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
		VI res(need, 0);
		FOR(i, 0, need)
			if (fa[i].x > 0.5)
				res[i] = 1;
				
		return res;
	}
};

int n, k;
VI a;

VI power(VI vec, int pw)
{
	VI res = vec;
	--pw;
	while(pw)
	{
		if (pw & 1)
			res = FFT::mult(res, vec);
		vec = FFT::mult(vec, vec);
		pw >>= 1;
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> k;
	a.resize(n);
	FOR(i, 0, n)
		cin >> a[i];
	
	VI vec(1001, 0);
	FOR(i, 0, n)
		vec[a[i]] = 1;
		 
	VI res = power(vec, k);
	FOR(i, 0, SZ(res))
		if (res[i])	
			cout << i << " " ;
	
	cout << endl;	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}