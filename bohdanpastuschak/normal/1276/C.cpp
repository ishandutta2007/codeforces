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

vector<vector<int>> ans;

void check()
{
	FOR(i, 0, SZ(ans))
	{
		VI tut = ans[i];
		sort(ALL(tut));
		tut.resize(unique(ALL(tut)) - tut.begin());
		assert(SZ(tut) == SZ(ans[i]));
	}
	
	FOR(i, 0, SZ(ans[0]))
	{
		VI tut(SZ(ans));
		FOR(j, 0, SZ(ans)) tut[j] = ans[j][i];
		sort(ALL(tut));
		tut.resize(unique(ALL(tut)) - tut.begin());
		assert(SZ(tut) == SZ(ans));
	}
}

void solve(int n, int m, set<PII>& S)
{
	ans.assign(n, vector<int>(m, 0));
	vector<PII> vec;
	for(auto i: S) vec.PB({i.Y, i.X});
	//vec = {{1, 1}, {2, 2}, {3, 1}};
	//n = m = 2;
	int x = 0, y = 0;
	int ryad = 0;
	
	for(auto tut: vec)
	{
		int chyslo = tut.X, cnt = tut.Y;
		while(cnt--)
		{
			ans[x][y] = chyslo;
			x++;
			y++;
			if (x < n && y < m) continue;
			
			if (x == n)
			{
				if(n < m)
				{
					ryad--;
					if (ryad < 0) ryad += m;
				}
				else ryad++;
				
				x = 0;
				y = ryad;
				continue;
			}
			
			y -= m;						
		}
	}	
	
	check();
	cout << n * m << endl;
	cout << n << ' ' << m << endl;
	FOR(i, 0, n) 
	{
		FOR(j, 0, m) cout << ans[i][j] << ' ';
		cout << endl;
	}
	
	exit(0);
}

const int N = 400000 + 7;
VI dil[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n = 400000;
	cin >> n;
	
	FOR(i, 1, n + 1) for(int j = i; j <= n; j += i)
		dil[j].PB(i);
		
	map<int, int> mp;
	FOR(i, 0, n)
	{
		int x = 1;
		cin >> x;
		mp[x]++;
	}
	
	set<PII> S;
	for(auto i: mp)
		S.insert({i.Y, i.X});
	
	int cnt_diff = SZ(S);
	int most = S.rbegin()->X;
	
	RFOR(SQ, n + 1, 1)
	{
		for(auto sm: dil[SQ])
		{
			int bg = SQ / sm;
			if (sm > bg) break;
			if (cnt_diff < bg) continue;
			if (most > sm) continue;
			solve(sm, bg, S);
		}		
		
		auto it = S.end();
		--it;
		auto tut = *it;
		S.erase(it);
		tut.X--;
		assert(tut.X > 0);
		S.insert(tut);
		most = S.rbegin()->X;
	}
	
	assert(false);
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}