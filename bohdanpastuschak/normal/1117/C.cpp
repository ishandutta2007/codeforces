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
const LL INF = 2e9 + 147;
const LL LINF = INF * INF;

const int MAX = 1 << 18;
LL dx, dy;
int n;
string s;
int pref_x[MAX];
int pref_y[MAX];

LL get(int id)
{
	LL pox = pref_x[n - 1];
	LL poy = pref_y[n - 1];
	
	LL zmx = pref_x[id];
	LL zmy = pref_y[id];
	
	LL L = 0, R = INF, M;
	LL lef = abs(R * pox + zmx - dx) + abs(R * poy + zmy - dy);
	if (lef > R * n + id + 1)
		return LINF;
	while(R - L > 1)
	{
		M = (L + R) / 2;
		LL lef = abs(M * pox + zmx - dx) + abs(M * poy + zmy - dy);
		if (lef <= M * n + id + 1)
			R = M;
		else
			L = M;
	}
	
	M = L;
	lef = abs(M * pox + zmx - dx) + abs(M * poy + zmy - dy);
	if (lef > M * n + id + 1)
		M = R;
	
	return M * n + id + 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	
	dx = a3 - a1;
	dy = a4 - a2;
	
	cin >> n >> s;
	if (s[0] == 'U')
		++pref_y[0];
	if (s[0] == 'D')
		--pref_y[0];
	if (s[0] == 'L')
		--pref_x[0];
	if (s[0] == 'R')
		++pref_x[0];
	FOR(i, 1, n)
	{
		pref_x[i] = pref_x[i - 1];
		pref_y[i] = pref_y[i - 1];
				
		if (s[i] == 'U')
			++pref_y[i];
		if (s[i] == 'D')
			--pref_y[i];
		if (s[i] == 'L')
			--pref_x[i];
		if (s[i] == 'R')
			++pref_x[i];
	}
	
	LL ans = LINF;
	FOR(i, 0, n)
		ans = min(ans, get(i));
	
	if (ans == LINF)
		ans = -1;
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}