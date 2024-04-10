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

const int N = 1 << 20;
int n;
vector<PII> e;
int d[N];
bool P[N];

void add(int u, int v)
{
	assert(u != v);
	if (u > v)
		swap(u, v);
		
	e.PB({u, v});
	d[u]++;
	d[v]++;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	FOR(i, 2, N)
		P[i] = 1;
	FOR(i, 2, N)
		if (P[i])
			for(LL j = i *(LL) i; j < N; j += i)
				P[j] = 0;
	
	
	cin >> n;
	
	FOR(i, 1, n)
		add(i, i + 1);
	
	add(1, n);
	int x = 1, y = n / 2 + 1;
	while(!P[SZ(e)])
	{
		add(x, y);
		++x;
		++y;
	}
		
	sort(ALL(e));
	FOR(i, 0, SZ(e) - 1)
		assert(e[i] != e[i - 1]);
	
	FOR(i, 1, n + 1)
		assert(P[d[i]]);
		
	cout << SZ(e) << endl;
	for(auto i: e)
		cout << i.X << ' ' << i.Y << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}