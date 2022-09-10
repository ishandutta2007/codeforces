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

const int MAX = 1 << 10;
int n;
PII x[MAX];
PII a[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> x[i].X >> x[i].Y;
	FOR(i, 0, n)
		cin >> a[i].X >> a[i].Y;
	
	vector<PII> A(n);
	FOR(i, 0, n)
		A[i] = a[i];
	sort(ALL(A));
	
	FOR(i, 0, n)
	{
		int dx = x[0].X + a[i].X;
		int dy = x[0].Y + a[i].Y;
		
		vector<PII> tut(n);
		FOR(j, 0, n)
			tut[j] = {dx - x[j].X, dy - x[j].Y};
		
		sort(ALL(tut));
		if (tut == A)
		{
			cout << dx << " " << dy << endl;
			return 0;
		}
	}
	
	assert(0);
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}