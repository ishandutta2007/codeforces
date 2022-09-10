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

int n;
const int MAX = 1 << 17;
int a[MAX];
int cnt[MAX];
VI groups[MAX];
int ptr[MAX];

void bad()
{
	cout << "Impossible" << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		a[i] = n - a[i];
		cnt[a[i]]++;
	}
	
	FOR(i, 1, n + 1)
		if (cnt[i] % i)
			bad();
	
	int hat = 0;
	FOR(i, 1, n + 1)
		FOR(j, 0, cnt[i])
		{
			if (j % i == 0)
				++hat;
			groups[i].PB(hat);
		}
			
	cout << "Possible" << endl;
	FOR(i, 0, n)
	{
		if (i)
			cout << ' ';
		int gr = a[i];
		cout << groups[gr][ptr[gr]++];
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}