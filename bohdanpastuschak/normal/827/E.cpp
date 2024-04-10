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

	void multiply(VI&a, VI&b, VI& res)
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
		res.resize(need);
		FOR(i, 0, need)
			if (fa[i].x > 0)
				res[i] = fa[i].x + 0.5;
			else
				res[i] = fa[i].x - 0.5;
	}
};

const int MAX = 1 << 19;
int n;
char s[MAX];
VI a, b;
bool ok [MAX];

void print(VI& x)
{
	cout << "---------------" << endl;
	FOR(i, 0, SZ(x))
		cout << x[i] << " " ;
	cout << endl << "---------------" << endl;
}

void solve()
{
	scanf("%d%s", &n, &s);
	
	a.resize(n), b.resize(n);
	FOR(i, 0, n)
		if (s[i] == 'V')
			a[i] = 1;
		else
			a[i] = 0;
	
	FOR(i, 0, n)
		if (s[i] == 'K')
			b[n - 1 - i] = 1;
		else
			b[n - 1 - i] = 0;
	
	//print(a);
	//print(b);
	VI res;
	FFT::multiply(a, b, res);
	//print(res);
	FOR(i, 1, n + 1)
		ok[i] = 1;
	
	FOR(i, 0, SZ(res))
		if (res[i])
		{
			int v = abs(i + 1 - n);
			if (v <= n)
				ok[v] = 0;
		}
	
	FOR(i, 1, n + 1)
		if (ok[i])			
			for(int k = i + i; k <= n; k += i)
				if (ok[k] == 0)
					ok[i] = 0;
		
	int cnt = 0;
	FOR(i, 1, n + 1)
		if (ok[i])
			++cnt;
	
	printf("%d\n", cnt);
	FOR(i, 1, n + 1)
		if (ok[i])
			printf("%d ", i);

	printf("\n");
}

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		solve();
		puts("");
	}
	
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}