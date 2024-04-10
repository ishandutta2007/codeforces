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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 1 << 17;
int f[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	f[2] = 2;
	f[3] = 3;
	FOR(i, 4, N)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
		
	string s;
	cin >> s;
	int n = SZ(s);
	
	VI a;
	int cnt = 0;
	FOR(i, 0, n)
	{
		if (s[i] == 'm' || s[i] == 'w')
		{
			cout << 0 << endl;
			return 0;
		}
		
		if (s[i] != 'u' && s[i] != 'n')
		{
			if (cnt > 1) a.PB(cnt);
			cnt = 0;
			continue;
		}
		
		if (i && s[i] != s[i - 1])
		{
			if (cnt > 1) a.PB(cnt);
			cnt = 0;
		}
		
		cnt++;
	}
	
	if (cnt > 1) a.PB(cnt);
	
	int ans = 1;
	for(auto i: a)
		ans = (ans * (LL) f[i]) % mod;	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}