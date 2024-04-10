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
const LL INF = 1e9;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct pt
{
	int x, y, z;
};

const int N = 1 << 11;
int n;
pt a[N];
char u[N];

int get(int i, int j)
{
	return abs(a[i].x - a[j].x) +  abs(a[i].y - a[j].y) + abs(a[i].z - a[j].z);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i].x >> a[i].y >> a[i].z;
	
	FOR(it, 0, n >> 1)
	{
		int id1 = 0;
		FOR(i, 0, n)
			if (!u[i])
			{
				id1 = i;
				break;
			}
		
		int id2;
		FOR(i, id1 + 1, n)
		{
			if (u[i]) continue;
			id2 = i;
			break;
		}
		
		FOR(i, id2 + 1, n)
		{
			if (u[i]) continue;
			if (get(id1, id2) > get(id1, i))
				id2 = i;
		}
		
		u[id1] = u[id2] = 1;
		cout << id1 + 1 << ' ' << id2 + 1 << '\n';
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}