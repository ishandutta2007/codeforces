#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 2e5 + 47;

LL n, k;
LL a[MAX];
int next[MAX];
int prev[MAX];
int cnt[MAX];

LL mine()
{
	FOR(i, 1, n + 1)
	{
		cnt[i] = cnt[i - 1];
		if (a[i] == 1)
			cnt[i]++;
	}

	LL ans = 0;
	int last = -1;
	RFOR(i, n + 1, 1)
	{
		next[i] = last;

		if (a[i] != 1)
			last = i;
	}

	last = -1;
	FOR(i, 1, n + 1)
	{
		prev[i] = last;
		if (a[i] != 1)
			last = i;
	}

	if (k == 1)
		ans += n;

	FOR(i, 1, n + 1)
	{
		if (a[i] == 1)
			continue;

		if (next[i] == -1)
			continue;

		LL prod = a[i], suma = a[i];
		LD val = prod;
		int j = next[i];

		while(j != -1)
		{
			suma += a[j];
			val *= a[j];

			if (val > LINF)
				break;

			prod *= a[j];

			if (prod % k == 0)
			{
				LL m = prod / k - suma;
				int mizh = cnt[j] - cnt[i];
				if (m >= mizh)
				{
					int zliva = cnt[i];
					if (prev[i] != -1)
						zliva = cnt[i] - cnt[prev[i]];

					int sprava = cnt[n];
					if (next[j] != -1)
						sprava = cnt[next[j]];

					sprava -= cnt[j];

					m -= mizh;
					if (m <= zliva + sprava)
					{
						zliva = min(zliva, (int)m);
						sprava= min(sprava, (int)m);

						ans += zliva + sprava - m + 1;
						//cout << m << endl;
						//cout << i << " " << j << " : " << zliva << " " << sprava << endl;
					}
				}
			}

			j = next[j];
		}
	}

	return ans;
}

LL ok()
{
	VI V;
	REP(i, n)
		if (a[i] > 1)
			V.PB(i);
	int pos = 0;
	V.PB(n);
	LL ans = 0;
	REP(i, n)
	{
		while (V[pos] < i)
			pos++;
		int j = pos;
		LL p = a[V[j]], s = a[V[j]] + V[j] - i;
		LD pd = p;
		int d = 0;
		d += a[i] == 1 && k == 1;

		while (pd < 5e18 && V[j] < n)
		{
			d += (p % k == 0 && p / k - s >= 0 && p / k - s < V[j + 1] - V[j]);
			j++;
			if (V[j] == n)
				break;
			p *= a[V[j]];
			pd *= a[V[j]];
			s += V[j] - V[j - 1] - 1 + a[V[j]];
		}

		ans += d;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

//	int t = 1000;
//	while(t--)
//	{
//		int n = rand() % 10 + 5;
//		int k = rand() % 7 + 1;
//		cout << n << " " << k << endl;
//		FOR(i, 0, n)
//			cout << 1 + rand() % 3 << endl;
//	}
//
//	return 0;

	while(cin >> n >> k)
	{
		FOR(i, 1, n + 1)
			cin >> a[i];

		LL R = mine();
		cout << R << endl;
		continue;

		FOR(i, 0, n)
			swap(a[i], a[i + 1]);

		//break;
		LL O = ok();
		if (O == R)
			continue;


		cout << R << " " << O << endl;
		cout << n << " " << k << endl;
		FOR(i, 0, n)
			cout << a[i] << " " ;

		cout << endl << endl;
	}

	return 0;
}