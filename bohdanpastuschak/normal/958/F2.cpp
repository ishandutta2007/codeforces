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
const LL MAX = 2e5 + 47;

int n, m;
int a[MAX];
int k[MAX];
VI pos[MAX];
int curr[MAX];
set<PII> s;
set<PII>::iterator it;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i], --a[i];
		
	FOR(i, 0, m)
		cin >> k[i];
		
	FOR(i, 0, n)
		pos[a[i]].push_back(i);
		
	bool can = 1;
	FOR(i, 0, m)
		if (SZ(pos[i]) < k[i])
			can = 0;
			
	if (!can)
	{
		cout << -1 << endl;
		return 0;
	}
	
	int ans = n;
	FOR(i, 0, m)
		curr[i] = k[i] - 1;
		
	FOR(i, 0, m)
		if (curr[i] >= 0)
			s.insert(MP(pos[i][curr[i]], i));
	
	int len = 0;
	FOR(i, 0, m)
		len += k[i];
	
	//cout << len << endl;
	FOR(now, 0, n)
	{
		it = s.end();
		--it;
		PII vel = *it;
		
		ans = min(ans, vel.X - now + 1 - len);
		//cout << now <<" " << ans << endl;
		int i = a[now];
		PII zara = MP(pos[i][curr[i]], i);
		s.erase(zara);
		
		curr[i]++;
		if (curr[i] == SZ(pos[i]))
			break;
			
		zara.X = pos[i][curr[i]];			
		s.insert(zara);			
	}	
	
	cout << ans << endl;
	return 0;
}