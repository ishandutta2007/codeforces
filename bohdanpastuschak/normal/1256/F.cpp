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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool f(string s)
{
	int n = SZ(s);
	bool res = 0;
	FOR(i, 0, n) FOR(j, i + 1, n) res ^= (s[i] > s[j]);
	return res;
}

bool solve()
{
	int n;
	string s, t;
	cin >> n >> s >> t;
	string S = s, T = t;
	sort(ALL(S));
	sort(ALL(T));
	if (S != T) return false;
	S.resize(unique(ALL(S)) - S.begin());
	T.resize(unique(ALL(T)) - T.begin());
	if (SZ(S) < n || SZ(T) < n) return true;
	if (f(s) == f(t)) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		bool tut = solve();
		if (tut) cout << "YES\n";
		else cout << "NO\n";
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}