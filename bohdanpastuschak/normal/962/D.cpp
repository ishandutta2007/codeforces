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
#define next fake_next
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

int n;
LL a[MAX];
map<LL, set<int> > mp;
set<LL> dwa;
map<LL, set<int> >:: iterator it;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(i, 0, n)
		mp[a[i]].insert(i);
		
	for(it = mp.begin(); it != mp.end(); ++it)
		if (SZ(it->second) > 1)
			dwa.insert(it->first);
	
	while(SZ(dwa))
	{	
		LL id = *dwa.begin();
		dwa.erase(id);
		
		int i1, i2;
		i1 = *mp[id].begin();
		mp[id].erase(i1);
		
		i2 = *mp[id].begin();
		mp[id].erase(i2);
		
		a[i1] = -1;
		a[i2] *= 2LL;
		
		mp[a[i2]].insert(i2);
		if (SZ(mp[id]) > 1)
			dwa.insert(id);
			
		if (SZ(mp[a[i2]]) > 1)
			dwa.insert(a[i2]);
	}
	
	int cnt = 0;
	FOR(i, 0, n)
		if (a[i] != -1)
			++cnt;
			
	cout << cnt << endl;	
	FOR(i, 0, n)
		if (a[i] != -1)
			cout << a[i] << " " ;
		
	return 0;
}