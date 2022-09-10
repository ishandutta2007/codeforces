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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 20;
int n;
int a[N];
int b[N];
PII v[N];
int ptr;

LL calc()
{
	LL ans = 0;
	FOR(i, 1, ptr) ans += v[i].X * (LL) (v[i].Y - v[0].Y);
	
	LL zliva = v[0].X;
	LL sprava = 0;
	FOR(i, 1, ptr) sprava += v[i].X;
	
	LL curr = ans;
	
	FOR(i, 1, ptr)
	{
		curr += (v[i].Y - v[i - 1].Y) * (LL) zliva;
		curr -= (v[i].Y - v[i - 1].Y) * (LL) sprava;
		ans = min(ans, curr);
		zliva += v[i].X;
		sprava -= v[i].X;
	}
	
	return ans;
}

LL check(LL x)
{
	FOR(i, 0, n) b[i] = a[i] % x;
	
	LL ans = 0;
	ptr = 0;
	LL su = 0;
	FOR(i, 0, n)
	{
		LL tut = min(x - su, (LL)b[i]);
		b[i] -= tut;
		su += tut;
		v[ptr++] = {tut, i};
		if (su == x)
		{
			su = 0;
			ans += calc();
			ptr = 0;
			--i;
		}		
	}
	
	assert(su == 0);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	LL s = 0;
	FOR(i, 0, n) s += a[i];
	
	if (s == 1)
	{
		cout << -1;
		return 0;
	}
	
	LL ans = LINF;
	
	for(LL i = 2; i * i <= s; ++i)
		if (s % i == 0)
		{
			while(s % i == 0) s /= i;
			ans = min(ans, check(i));
		}
	
	if (s > 1) ans = min(ans, check(s));
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}