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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void bad()
{
	cout << "NO" << endl;
	exit(0);
}

const int N = 1 << 17;
int n;
PII a[N];
PII b[N];

void go()
{
	vector<pair<int, PII>> e;
	FOR(i, 0, n)
	{
		e.PB({a[i].X, {-1, i}});
		e.PB({a[i].Y, {1, i}});
	}
	
	sort(ALL(e));
	
	set<PII> po_kin_b, po_poc_b;
	
	for(auto i: e)
	{
		int hto = i.Y.Y;
		if (i.Y.X == -1)
		{
			po_kin_b.insert({b[hto].Y, hto});
			po_poc_b.insert({b[hto].X, hto});
		}
		else
		{
			po_kin_b.erase({b[hto].Y, hto});
			po_poc_b.erase({b[hto].X, hto});
		}			
		
		if (SZ(po_kin_b) == 0) continue;
		int pravo = po_kin_b.begin()->X;
		int livo = po_poc_b.rbegin()->X;
		if (livo > pravo) bad();
	}	
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i].X >> a[i].Y >> b[i].X >> b[i].Y;
	
	go();
	FOR(i, 0, n) swap(a[i], b[i]);
	go();
	
	cout << "YES" << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}