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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

const int MAX = 2000 + 7;
int a[MAX];
int b[MAX];
int n, m;
LL x;
LL pa[MAX];
LL pb[MAX];
LL lena[MAX];
LL lenb[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, m)
		cin >> b[i];
	
	cin >> x;
	LL s = 0;
	pa[0] = a[0];
	pb[0] = b[0];
	
	FOR(i, 1, n)
		pa[i] = pa[i - 1] + a[i];
	FOR(i, 1, m)
		pb[i] = pb[i - 1] + b[i];
	
	FOR(i, 1, n + 1)
	{
		LL best = pa[i - 1];
		FOR(last, i, n)
			best = min(best, pa[last] - pa[last - i]);
		
		lena[i] = best;
	}
	
	FOR(i, 1, m + 1)
	{
		LL best = pb[i - 1];
		FOR(last, i, m)
			best = min(best, pb[last] - pb[last - i]);
		
		lenb[i] = best;
	}
		
	FOR(i, 1, n + 1)
	{
		LL tut = x / lena[i];
		auto it = upper_bound(lenb, lenb + m + 1, tut) - lenb - 1;
		s = max(s, (LL)i * it);
	}	
	
	cout << s << endl;
	cerr << "n != m" << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}