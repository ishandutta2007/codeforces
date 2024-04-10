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

const int N = 1 << 19;
int n;
int a[N];
int b[N];
int chas[N];

int solve()
{
	int ptr = 0;
	int in_a = n;
	
	while(1)
	{
		int head = b[ptr];
		b[n + ptr] = 0;
		ptr++;
		a[in_a++] = head;		
		if (head == 1)
			break;
	}	
	
	FILL(chas, 0);
	FOR(i, ptr, ptr + n)
		if (b[i])
			chas[b[i]] = i - ptr;
	
	int mx = 0;
	FOR(i, 1, n + 1)
		if (chas[i] > 0)
			mx = max(mx, chas[i] - i + 2);
	
	return ptr + n + mx;
}

int solve_b()
{
	bool moje = 1;
	int id = -1;
	FOR(i, 0, n)
		if (b[i] == 1)
			id = i;
	
	FOR(i, id, n)
		moje &= b[i] == i - id + 1;
	
	if (!moje)
		return solve();
	
	int nast = b[n - 1] + 1;
	
	FOR(i, 0, id)
	{
		if (b[i] == 0)
			continue;
			
		chas[b[i]] = i + 1;		
	}
	
	FOR(i, nast, n + 1)
		if (chas[i] > i - nast)
			return solve();
	
	return id;
}

int solve_a()
{
	int mx = 0;
	FOR(i, 0, n)
	{
		if (b[i] == 0)
			continue;
		
		mx = max(mx, i + 2 - b[i]);
	}
	
	return n + mx;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	FOR(i, 0, n)
		cin >> b[i];
	
	int ans = 0;
	bool odyn = 0;
	FOR(i, 0, n)
		odyn |= b[i] == 1;
	
	if (odyn)
		ans = solve_b();
	else
		ans = solve_a();
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}