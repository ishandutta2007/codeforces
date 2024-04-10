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

const int MAX = 300 + 7;
int n, m;
int a[MAX];
PII q[MAX];

bool ye(int x, int y, int z)
{
	return x >= y && x <= z;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(i, 0, m)
	{
		cin >> q[i].X >> q[i].Y;
		q[i].X--;
		q[i].Y--;
	}
	
	int best = -1;
	PII id(-1, -1);
	
	FOR(i, 0, n)
		FOR(j, 0, n)
		{
			int zara = a[i] - a[j];
			FOR(k, 0, m)
				zara += ye(j, q[k].X, q[k].Y) && !ye(i, q[k].X, q[k].Y);
			
			if (zara > best)
			{
				best = zara;
				id = MP(i, j);				
			}
		}
	
	cout << best << endl;
	//cout << id.X << ' ' << id.Y << endl;
	VI ans;
	FOR(k, 0, m)
		if (ye(id.Y, q[k].X, q[k].Y) && !ye(id.X, q[k].X, q[k].Y))
			ans.PB(k + 1);
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}