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
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 10;
int n, m, k;
string s[N];
int ans[N][N];

char get(int x)
{
	if (x < 10) return (char)('0' + x);
	x -= 10;
	if (x < 26) return (char)('a' + x);
	x -= 26;
	assert(x < 26);
	return (char)('A' + x);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		FOR(i, 0, n) cin >> s[i];
		
		int cnt = 0;
		FOR(i, 0, n) FOR(j, 0, m) cnt += s[i][j] == 'R';
		
		vector<int> bude(k);
		FOR(i, 0, k) bude[i] = cnt / k;
		int suma = cnt / k * k;
		FOR(i, 0, cnt - suma) bude[i]++;
		
		int ptr = 0;
		int vje = 0;
		
		FOR(i, 0, n)
		{
			if (i & 1)
			{
				RFOR(j, m, 0)
				{
					if (s[i][j] == 'R')
					{
						if (vje == bude[ptr])
						{
							ptr++;
							vje = 0;
						}
						vje++;
					}
					
					ans[i][j] = ptr;
				}
			}
			else
			{
				FOR(j, 0, m)
				{
					if (s[i][j] == 'R')
					{
						if (vje == bude[ptr])
						{
							ptr++;
							vje = 0;
						}
						vje++;
					}
					
					ans[i][j] = ptr;
				}
			}
		}
		
		FOR(i, 0, n)
		{
			FOR(j, 0, m) cout << get(ans[i][j]);
			cout << '\n';
		}
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}