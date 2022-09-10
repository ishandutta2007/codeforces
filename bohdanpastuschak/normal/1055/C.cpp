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

int MOD(int x, int m)
{
	return ((x % m) + m) % m;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	int la, ra, ta;
	int lb, rb, tb;
	
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	
	int lena = ra - la + 1;
	int lenb = rb - lb + 1;
	
	int ans = 0;
	int G = __gcd(ta, tb);
	int x, y;
	
	x = MOD(lb - la, G);
	y = G - x;
	
	ans = max(ans, min(lenb, lena - x));
	ans = max(ans, min(lena, lenb - y));	
	cout << ans << endl;
	return 0;
}