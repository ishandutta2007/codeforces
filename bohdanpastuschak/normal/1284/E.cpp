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
#define debug(a) cout << #a << " = " << a << endl;

const long double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct pt
{
	int x, y;
	pt(){}
	pt(int a, int b)
	{
		x = a;
		y = b;
	}
	
	LL operator*(const pt& p) const
	{
		return x * (LL) p.y - y * (LL) p.x;
	}
	
	int hp() const
	{
		return y < 0 || (y == 0 && x < 0);
	}
};

const int N = 2500 + 47;
int n;
pt a[N];

pt get(int i, int j)
{
	int dx = a[i].x - a[j].x;
	int dy = a[i].y - a[j].y;
	return pt(dx, dy);
}

int cmp(pt x, pt y)
{
	if (x.hp() != y.hp()) return x.hp() < y.hp();
	return x * y > 0;
}

LL triangle_area_2 (int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (LL)(y3 - y1) - (y2 - y1) *(LL) (x3 - x1);
}

bool ok(pt x, pt y)
{
	return triangle_area_2(x.x, x.y, 0, 0, y.x, y.y) <= 0;
}

LL solve(int id)
{
	vector<pt> kut;
	FOR(i, 0, n) if (i != id) kut.PB(get(i, id));
	sort(ALL(kut), cmp);
	LL ans = 0;	
	int sz = SZ(kut);
	kut.resize(sz + sz);
	FOR(i, sz, sz + sz) kut[i] = kut[i - sz];
	
	int last = 0;
	FOR(i, 0, sz)
	{
		last = max(last, i);
		while(last < sz + i && ok(kut[i], kut[last])) last++;
		int cnt = last - i - 1;
		ans += cnt * (cnt - 1) / 2;		
	}
	
	ans = (n - 1) * (LL) (n - 2) * (n - 3) / 6 - ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		
	cin >> n;
	FOR(i, 0, n) cin >> a[i].x >> a[i].y;
	
	LL ans = 0;
	FOR(i, 0, n)
		ans += solve(i);
		
	ans *= (n - 4);
	assert(ans % 2 == 0);
	ans /= 2;
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}