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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
int a[N];
int cnt[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	LL ans = 0;
	FOR(i, 0, n) ans += a[i];
	int q;
	cin >> q;
	map<PII, int> mp;
	while(q--)
	{
		int s, t, u;
		cin >> s >> t >> u;
		--s; --u;
		if (mp.count({s, t}))
		{
			int bulo = mp[MP(s, t)];
			ans -= max(0, a[bulo] - cnt[bulo]);
			cnt[bulo]--;
			ans += max(0, a[bulo] - cnt[bulo]);
		}
		
		if (u >= 0)
		{
			mp[MP(s, t)] = u;
			int bulo = u;
			ans -= max(0, a[bulo] - cnt[bulo]);
			cnt[bulo]++;
			ans += max(0, a[bulo] - cnt[bulo]);
		}	
		else mp.erase(MP(s, t));
		assert(ans > 0);
		cout << ans << '\n';
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}