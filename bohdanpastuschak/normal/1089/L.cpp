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
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

const int MAX = 100 * 1000 + 7;

int a[MAX];
int b[MAX];
vector<int> c[MAX];
vector<int> d;

int main()
{
//    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("In.txt" , "r" , stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", a + i);
	}
	FOR(i, 0, n)
	{
		scanf("%d", b + i);
	}
	FOR(i, 0, n)
		c[a[i]].PB(b[i]);
	int unused = 0;
	FOR(i, 1, k + 1)
	{
		if(c[i].empty())
			unused++;
		sort(ALL(c[i]));
		FOR(j, 0, SZ(c[i]) - 1)
			d.PB(c[i][j]);
	}
	sort(ALL(d));
	LL ans = 0;
	FOR(i, 0, unused)
		ans += d[i];
	printf("%lld", ans);
	return 0;
}