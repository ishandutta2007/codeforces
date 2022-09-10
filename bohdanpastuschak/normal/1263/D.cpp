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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
int a[N];
char u[N];
bool zv[26][26];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		int mask = 0;
		for(auto x: s) mask |= 1 << (x - 'a');
		a[i] = mask;
	}
	
	sort(a, a + n);
	n = unique(a, a + n) - a;
	
	FOR(i, 0, n)
	{
		FOR(j, 0, 26) if (a[i] & (1 << j))
		{
			FOR(k, j + 1, 26) if (a[i] & (1 << k))	
				zv[j][k] = zv[k][j] = 1;
		}
	}
	
	FOR(k, 0, 26) FOR(i, 0, 26) FOR(j, 0, 26) 	
		zv[i][j] |= (zv[i][k] & zv[k][j]);
	
	FOR(i, 0, n) 
	{
		FOR(k, 0, 26) if (a[i] & (1 << k))
		{
			FOR(l, 0, 26) 			
				if (zv[k][l]) a[i] |= 1 << l;
			break;
		}
	}
	
	sort(a, a + n);
	n = unique(a, a + n) - a;
	cout << n << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}