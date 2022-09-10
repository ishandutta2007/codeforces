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

struct pt
{
	int x, y, z, id;
	bool operator<(const pt& p)const
	{
		if (x != p.x) return x < p.x;
		if (y != p.y) return y < p.y;
		if (z != p.z) return z < p.z;
		
		return id < p.id;
	}
};

const int N = 1 << 17;
int n;
pt a[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].id = i + 1;
	}
	
	map<int, vector<pt>> mp;
	FOR(i, 0, n)
		mp[a[i].x].PB(a[i]);
	
	for(auto& i: mp)
		sort(ALL(i.Y));
		
	vector<PII> ans;
	
	for(auto& i: mp)
	{
		map<int, vector<pt>> mp2;
		for(auto x: i.Y)
			mp2[x.y].PB(x);
		
		for(auto& x: mp2)
		{
			for(int y = 0; y < SZ(x.Y) - 1; y += 2)
				ans.PB({x.Y[y].id, x.Y[y + 1].id});
			reverse(ALL(x.Y));
			x.Y.resize(SZ(x.Y) % 2);			
		}
		
		vector<pt> vec;
		for(auto x: mp2)
			for(auto y: x.Y)
				vec.PB(y);
		
		for(int y = 0; y < SZ(vec) - 1; y += 2)
			ans.PB({vec[y].id, vec[y + 1].id});
			
		reverse(ALL(vec));
		vec.resize(SZ(vec) % 2);
		i.Y = vec;	
	}
	
	vector<pt> vec;
	for(auto i: mp)
		for(auto j: i.Y)
			vec.PB(j);
	
	for(int x = 0; x < SZ(vec); x += 2)
		ans.PB({vec[x].id, vec[x + 1].id});
	
	assert(SZ(ans) == n / 2);
	FOR(i, 0, n >> 1)
		cout << ans[i].X << ' ' << ans[i].Y << '\n';
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}