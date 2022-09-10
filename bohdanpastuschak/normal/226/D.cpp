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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 7;
int n, m;
int a[N][N];
int r[N];
int s[N];
bool treba_r[N];
bool treba_s[N];

bool calc()
{
	bool ok = 1;
	FOR(i, 0, n)
	{
		r[i] = 0;
		FOR(j, 0, m)
			r[i] += a[i][j];
		ok &= r[i] >= 0;
	}
	
	FOR(j, 0, m)
	{
		s[j] = 0;
		FOR(i, 0, n)
			s[j] += a[i][j];
		ok &= s[j] >= 0;
	}
	
	return ok;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
		FOR(j, 0, m)
			cin >> a[i][j];
	
	while(!calc())
	{
		int mn = INF, id = 0;
		FOR(i, 0, n)
			if (r[i] < mn)
				mn = r[i], id = i;
		
		FOR(i, 0, m)
			if (s[i] < mn)
				mn= s[i], id = i + n;
		
		if (id < n)
		{
			treba_r[id] ^= 1;
			FOR(j, 0, m)
				a[id][j] *= -1;
		}
		else
		{
			id -= n;
			treba_s[id] ^= 1;
			FOR(j, 0, n)
				a[j][id] *= -1;
		}
	}
	
	int cnt_r = 0, cnt_c = 0;
	FOR(i, 0, n)
		cnt_r += treba_r[i];
	FOR(i, 0, m)
		cnt_c += treba_s[i];
	
	cout << cnt_r;
	FOR(i, 0, n)
		if (treba_r[i])
			cout << ' ' << i + 1;
	
	cout << endl;
	cout << cnt_c;
	FOR(i, 0, m)
		if (treba_s[i])
			cout << ' ' << i + 1;
	
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}