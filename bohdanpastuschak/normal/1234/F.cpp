#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
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
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 20;
void conv_xor(int* a, int k)
{
	FOR(i, 0, k)
		FOR(j, 0, 1 << k)
			if (!(j & (1 << i)))
			{
				int u = a[j];
				int v = a[j + (1 << i)];
				a[j] = u + v;
				a[j + (1 << i)] = u - v;
			}
}

int a[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	
	string s;
	cin >> s;
	int n = SZ(s);
	FOR(i, 0, n)
		s[i] -= 'a';
	
	a[0]  = 1;
	FOR(i, 0, n)
	{
		int mask = 0;
		FOR(j, i, n)
		{
			if (mask & (1 << s[j]))
				break;
			mask |= 1 << s[j];
			a[mask] = 1;
		}
	}
	
	
	conv_xor(a, 20);
	FOR(i, 0, N)
		a[i] *= a[i];
	conv_xor(a, 20);		
	int ans = 0;
	FOR(i, 0, N)
		if (a[i])
			ans = max(ans, __builtin_popcount(i));
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}