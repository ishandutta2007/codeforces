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

const int N = 1 << 18;
int n;
int d[N];
PII e[N];
int ptr;
PII a[N];

void add(int x, int y)
{
	e[ptr++] = {x, y};
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> d[i];
		a[i] = {d[i], i};
	}
		
	sort(a, a + n);
	reverse(a, a + n);
	
	VI order;
	VI pos(2 * n + 1);
	
	FOR(i, 0, n)
	{
		order.PB(a[i].Y * 2 + 1);
		pos[a[i].Y * 2 + 1] = i;
	}
	
	FOR(i, 0, n - 1)
		add(order[i], order[i + 1]);
	
	int kin = order.back();
	FOR(i, 0, n)
	{
		int tut = a[i].Y * 2 + 1;
		int dist = a[i].X;	
		int id_posycija = pos[tut] + dist - 1;

		add(order[id_posycija], tut + 1);
		if (order[id_posycija] == kin)
		{
			order.PB(tut + 1);
			kin = tut + 1;
		}
	}	
	
	assert(ptr == n + n - 1);
	FOR(i, 0, ptr)
		cout << e[i].X << ' ' << e[i].Y << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}