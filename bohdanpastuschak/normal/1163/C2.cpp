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
const int INF = 1e9 + 47;
const LL LINF = INF *(LL) INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct pt
{
	int x, y;
};

#define PDD pair<double, double>
const int N = 1 << 10;
pt a[N];

PII go(int x, int y)
{
	if (x < 0)
		x *= -1, y *= -1;
	int xx = x, yy = y;
	if (yy < 0)
		yy *= -1;
		
	int g = __gcd(xx, yy);
	if (g)
	{
		x /= g;
		y /= g;
	}
	
	return MP(x, y);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int n;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i].x >> a[i].y;
	
	//vector<PDD> suka;
	map<PII, vector<PII>> mp;
	set<int> ss, zhepa;
	FOR(i, 0, n)
		FOR(j, i + 1, n)
		{
			if (a[i].x == a[j].x)
			{
				ss.insert(a[i].x);
				continue;
			}
			
			if (a[i].y == a[j].y)
			{
				zhepa.insert(a[i].y);
				continue;
			}
			
			//double s1 = (a[j].y - a[i].y + 0.0)/  (a[j].x - a[i].x);
			//double s2 = (a[i].y * a[j].x - a[i].x * a[j].y + 0.0)/  (a[j].x - a[i].x);
			//suka.PB(MP(s1, s2));
			PII m1 = go(a[j].y - a[i].y, a[j].x - a[i].x);
			PII m2 = go(a[i].y * a[j].x - a[i].x * a[j].y, a[j].x - a[i].x);
			
			mp[m1].PB(m2);		
		}
	
	/*double EPS = 1e-8;
	sort(ALL(suka));
	vector<vector<double>> vec;
	vector<double> tut;
	tut.PB(suka[0].Y);
	FOR(i, 1, SZ(suka))
	{
		if (suka[i].X <= suka[i - 1].X + EPS)
		{
			tut.PB(suka[i].Y);
			continue;
		}
		vec.PB(tut);
		tut.clear();
		tut.PB(suka[i].Y);
	}
	
	vec.PB(tut);
	for(auto& i: vec)
	{
		vector<double> blya;
		blya.PB(i[0]);
		FOR(j, 1, SZ(i))	
			if (i[j] > i[j - 1] + EPS)
				blya.PB(i[j]);
		i = blya;
	}*/
	
	LL all = SZ(ss) + SZ(zhepa);
	for(auto& i: mp)
	{
		sort(ALL(i.Y));
		i.Y.resize(unique(ALL(i.Y)) - i.Y.begin());
		all += SZ(i.Y);
	}
	
	LL tuta = SZ(ss) * (all - SZ(ss)) + SZ(zhepa) * (all - SZ(zhepa));
	for(auto i: mp)
		tuta += SZ(i.Y) * (all - SZ(i.Y));
	
	assert(tuta % 2 == 0);
	tuta /= 2;	
	cout << tuta << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}