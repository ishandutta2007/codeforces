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

const int MAX = 1 << 17;
int n, s;
int a[MAX][2];

void ok()
{
	cout << "YES";
	exit(0);
}
void bad()
{
	cout << "NO";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> s;
	--s;
	FOR(i, 0, n)
		cin >> a[i][0];
	FOR(i, 0, n)	
		cin >> a[i][1];
	
	if (!a[0][0])
		bad();
	
	if (a[s][0])
		ok();
	
	bool is = 0;
	FOR(i, s, n)
		is |= a[i][0] && a[i][1];
	
	if (is && a[s][1])
		ok();
	
	cout << "NO" << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}