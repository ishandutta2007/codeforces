#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

int n;
pair<PII, PII> a[1 << 20];
map<int, int> l, r, v, nz;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i].X.X >> a[i].X.Y >> a[i].Y.X >> a[i].Y.Y;
		l[a[i].X.X]++;
		r[a[i].Y.X]++;
		v[a[i].Y.Y]++;
		nz[a[i].X.Y]++;
	}
	
	FOR(i, 0, n)
	{
		int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
		
		map<int, int>::iterator it;
		
		it = l.end();
		--it;
		if (it->Y == 1 && it->X == a[i].X.X)
			--it;
		
		maxX = max(maxX, it->X);
		
		it = r.begin();
		if (it->Y == 1 && it->X == a[i].Y.X)
			it++;
		
		minX = min(minX, it->X);
				
		it = nz.end();
		--it;
		if (it->Y == 1 && it->X == a[i].X.Y)
			--it;
		
		maxY = max(maxY, it->X);		
		

		it = v.begin();
		if (it->Y == 1 && it->X == a[i].Y.Y)
			it++;
		
		minY = min(minY, it->X);
		
		
		if (minX >= maxX && minY >= maxY)
		{
			//cout << i << endl;
			//cout << minX << " " << minY << endl;
			cout << maxX << " " << maxY << endl;
			return 0;
		}
	}
	
	assert(0);
	return 0;
}