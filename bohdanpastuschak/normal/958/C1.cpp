#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1e3 + 47;
int n;
int p;
int sufSum[100000];
int	prefSum[100000];
int a[1000000];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> n >> p;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	prefSum[0] = a[0] % p;
	for(int i = 1; i < n; i++)
	{
		prefSum[i] = (prefSum[i - 1] + a[i]) % p;
	}
	sufSum[n - 1] = a[n - 1] % p; 
	for(int i = n - 2; i >= 0; i--)
	{
		sufSum[i] = (sufSum[i + 1] + a[i]) % p;
	}
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		ans = max(ans , prefSum[i] + sufSum[i + 1]);
	}
	cout << ans;
	return 0;
}