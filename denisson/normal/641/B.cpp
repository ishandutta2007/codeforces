#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//

#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)

//
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = 0;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 2e5 + 7;

int n, m, q1;
int a[107][107];
pair< pair<int, int>, pair<int, int> > q[10007];

void sd1(int l)
{
	int x = a[l][m - 1];
	for (int i = m - 1; i >= 1; i--)
		a[l][i] = a[l][i - 1];
	a[l][0] = x;
}

void sd2(int l)
{
	int x = a[n - 1][l];
	for (int i = n - 1; i >= 1; i--)
		a[i][l] = a[i - 1][l];
	a[0][l] = x;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen("stones.in", "r", stdin); freopen("stones.out", "w", stdout);
    srand(14123);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    
    cin >> n >> m >> q1;
    forn(i, q1)
	{
		cin >> q[i].XX.XX;
		if (q[i].XX.XX == 3)
			cin >> q[i].YY.XX >> q[i].YY.YY >> q[i].XX.YY;
		else
			cin >> q[i].XX.YY;
	}
    for (int i = q1 - 1; i >= 0; i--)
    {
		int type = q[i].XX.XX;
		if (type == 1)
		{
			int z = q[i].XX.YY;
			z--;
			sd1(z);
		}
		if (type == 2)
		{
			int z = q[i].XX.YY;
			z--;
			sd2(z);
		}
		if (type == 3)
		{
			int x = q[i].YY.XX, y = q[i].YY.YY, z = q[i].XX.YY;
			x--; y--;
			a[x][y] = z;
		}
	}
    
    forn(i, n)
	{
		forn(j, m)
			cout << a[i][j] << ' ';
		cout << LN;
	}
}
//190660JM