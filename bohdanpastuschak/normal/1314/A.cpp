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

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int n;
PII a[N];
vector<int> cost[N];

int main()
{	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector<int> all;
	FOR(i, 0, n) cin >> a[i].X, all.PB(a[i].X);
	FOR(i, 0, n) cin >> a[i].Y;
	
	sort(ALL(all));
	all.resize(unique(ALL(all)) - all.begin());
	
	FOR(i, 0, n) 
		cost[lower_bound(ALL(all), a[i].X) - all.begin()].PB(a[i].Y);
	
	LL ans = 0;
	
	multiset<PII> S;
	int last = -1;
	all.PB(INF * 2);
	
	FOR(i, 0, SZ(all))
	{
		int chas = all[i];
		int cnt = min(SZ(S), chas - last);
		
		for(int curr = last; cnt > 0; curr++, cnt--)
		{			
			PII mn = *S.rbegin();
			S.erase(S.find(mn));
			ans += mn.X * (LL) (curr - mn.Y);
		}		
				
		for(auto j: cost[i]) S.insert({j, chas});		
		last = chas;
	}			
	
	cout << ans << endl;
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}