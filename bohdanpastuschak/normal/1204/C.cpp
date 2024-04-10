#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 7;
const int M = 1 << 20;
int n, m;
int p[M];
string a[N];
int d[N][N];
int ans[M];
int ptr;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	cin >> m;
	FOR(i, 0, m)
		cin >> p[i], p[i]--;
	
	FOR(i, 0, n)
		FOR(j, 0, n)
			if (i != j)
				d[i][j] = INF;
	
	FOR(i, 0, n)
		FOR(j, 0, n)
			if (a[i][j] == '1')
				d[i][j] = 1;
	
	
	FOR(i, 0, n)
		FOR(j, 0, n)
			FOR(k, 0, n)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			
	ans[ptr++] = p[0];
	for(int i = 0; i < m;)
	{
		int j = i + 1;
		while(j < m && d[p[i]][p[j]] == j - i)
			j++;
					
		ans[ptr++] = p[j - 1];
		if (j == m)
			break;
			
		i = j - 1;
	}
		
	cout << ptr << endl;
	FOR(i, 0, ptr)
		cout << ans[i] + 1 << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}