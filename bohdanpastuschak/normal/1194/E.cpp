#include <bits/stdc++.h>
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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5001;
bitset<N> g[N];
int n;

struct pt
{
	LL x, y;
	void read()
	{
		cin >> x >> y;
	}
};

struct seg
{
	pt a, b;
	bool hor;
	void read()
	{
		a.read();
		b.read();
		if (a.y == b.y)
			hor = true;
		else
			hor = false;
	}
};

seg s[N];
int id_hor[N];
int id_ver[N];
 
inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) *(LL) area(a,b,d) <= 0
		&& area(c,d,a) *(LL) area(c,d,b) <= 0;
}

bool intersect(seg a, seg b)
{
	return intersect(a.a, a.b, b.a, b.b);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	FILL(id_hor, -1);
	FILL(id_ver, -1);
	
	cin >> n;
	FOR(i, 0, n)
		s[i].read();
	
	int cnt_hor = 0, cnt_ver = 0;
	
	FOR(i, 0, n)
	{
		if (s[i].hor)
			id_hor[i] = cnt_hor++;
		else
			id_ver[i] = cnt_ver++;
	}
	
	int m = -1;
	LL ans = 0;
	if (cnt_hor >= cnt_ver)
	{
		m = cnt_ver;
		FOR(i, 0, n)
		{
			if (!s[i].hor)
				continue;
				
			FOR(j, 0, n)
				if (i != j && intersect(s[i], s[j]))
					g[id_ver[j]][id_hor[i]] = 1;
		}
	}
	else
	{
		m = cnt_hor;
		FOR(i, 0, n)
		{
			if (s[i].hor)
				continue;
				
			FOR(j, 0, n)
				if (i != j && intersect(s[i], s[j]))
					g[id_hor[j]][id_ver[i]] = 1;
		}
	}
		
	FOR(i, 0, m)
		FOR(j, i + 1, m)
		{
			int tut = (g[i] & g[j]).count();
			ans += tut * (tut - 1) / 2;
		}
		
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}