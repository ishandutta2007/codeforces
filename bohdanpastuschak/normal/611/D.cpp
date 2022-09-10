#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

const int N = 5000 + 7;
int n;
string s;
LL hashi[N];
LL PW[N];
const int Mo = 47;
int dp[N][N];
int suma[N][N];
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

inline bool equal(int i, int j, int len)
{
	LL h1 = hashi[i + len - 1];
	if (i)
		h1 -= hashi[i - 1];
	LL h2 = hashi[j + len - 1];
	if (j)
		h2 -= hashi[j - 1];
	
	return h1 * PW[j - i] == h2;
}

inline bool f(int i, int len)
{
	int j = i + len;
	if (j + len > n)
		return 0;
	
	int mn = min(len, 5);
	FOR(k, 0, mn)
		if (s[i + k] != s[j + k])
			return s[i + k] < s[j + k];
	
	if (len == mn)
		return 0;
	
	if (equal(i, j, len))	
		return 0;
	
	int L = mn - 1, R = len, M;
	while(R - L > 1)
	{
		M = (L + R) >> 1;
		if (equal(i, j, M))
			L = M;
		else
			R = M;
	}
	
	assert(equal(i, j, L));
	assert(!equal(i, j, R));
	
	return s[i + L] < s[j + L];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
		
	n = 5000;
	s.resize(n);
	FOR(i, 0, n)
		s[i] = '0' + (rng() % 10);
	if (s[0] == '0')
		s[0] = '1' + (rng() % 9);
		
	cin >> n >> s;
	s += '1';
	PW[0] = 1;
	FOR(i, 1, N)
		PW[i] = PW[i - 1] * Mo;
	
	FOR(i, 0, n)
	{
		hashi[i] = s[i] * PW[i];
		if (i)
			hashi[i] += hashi[i - 1];
	}

	FOR(i, 1, n + 2)
		suma[n][i] = 1;
		
	RFOR(i, n, 0)
	{
		if (s[i] == '0')
			continue;
		
		FOR(len, 1, n - i + 1)
		{
			dp[i][len] = suma[i + len][len + 1];
			if (f(i, len))
				dp[i][len] = add(dp[i][len], dp[i + len][len]);
		}
		
		RFOR(len, n + 1, 1)
			suma[i][len] = add(suma[i][len + 1], dp[i][len]);
	}	
	
	int ans = 0;
	FOR(len, 1, n + 1)
		ans = add(ans, dp[0][len]);
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}