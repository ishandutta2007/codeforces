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

const int N = 1 << 17;
int n;
vector<PII> black, white;
int p[N];
int sz[N];
vector<pair<int, PII>> e;
PII r[N];

int find(int x)
{
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (sz[x] < sz[y])
		swap(x, y);
	sz[x] += sz[y];
	p[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
	{
		int x, y;
		cin >> x >> y;
		r[i + 1] = {y, x};
		if (x == 0)
			black.PB({y, i + 1});
		else
			white.PB({y, i + 1});
	}
	
	FOR(i, 1, n + 1)
		p[i] = i, sz[i] = 1;
	
	set<PII> s1, s2;
	for(auto i: white)
		if (i.X)
			s1.insert(i);
	for(auto i: black)
		if (i.X)
			s2.insert(i);
	
	int pw = -1, pb = -1;
	while(SZ(s1) && SZ(s2))
	{
		PII v1 = *s1.begin();
		PII v2 = *s2.begin();
		
		s1.erase(s1.begin());
		s2.erase(s2.begin());
		
		int waga = min(v1.X, v2.X);
		v1.X -= waga;
		v2.X -= waga;
		
		assert(find(v1.Y) != find(v2.Y ));
		unite(v1.Y, v2.Y);
		
		pw = v1.Y;
		pb = v2.Y;
		
		e.PB({waga, {v1.Y, v2.Y}});
		if (v1.X)
			s1.insert(v1);
		if (v2.X)
			s2.insert(v2);
	}
	
	if (pw == -1)
	{
		FOR(i, 1, n + 1)
			if (r[i].Y)
				pw = i;
			else
				pb = i;
	}
	
	FOR(i, 1, n + 1)
		if (find(i) != find(pw))
		{
			if (r[i].Y)
			{
				e.PB({0, {i, pb}});
				unite(i, pb);
			}
			else
			{
				e.PB({0, {i, pw}});
				unite(i, pw);
			}
		}
	
	assert(SZ(e) == n - 1);
	for(auto i: e)
		cout << i.Y.X << ' ' << i.Y.Y << ' ' << i.X << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}