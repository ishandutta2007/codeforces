#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
vector<int> g[N];
char used[N];
string s;
int cnt[26];

void dfs(int v)
{
	cnt[s[v] - 'a']++;
	used[v] = 1;
	for(auto i: g[v]) if (!	used[i])
		dfs(i);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		cin >> s;
		FOR(i, 0, n) g[i].clear(), used[i] = 0;
		FOR(i, 0, n) g[i].PB(n - 1 - i);
		FOR(i, 0, k)
			for(int j = i + k; j < n; j += k)
				g[i].PB(j), g[j].PB(i);
			
		int ans = 0;
		FOR(i, 0, n) if (!used[i])
		{
			FILL(cnt, 0);
			dfs(i);
			int mx = 0,all= 0;
			FOR(j, 0, 26) setmax(mx, cnt[j]), all += cnt[j];
			ans += all - mx;
		}
		
		cout << ans << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}