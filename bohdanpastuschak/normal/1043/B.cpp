#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

const int MAX = 1 << 10;
int n;
int a[MAX];
bool was[MAX];
int x[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n;
	FOR(i, 1, n + 1)
		cin >> a[i];
	
	VI ans;
	FOR(k, 1, n + 1)
	{
		bool ok = 1;
		FILL(was, 0);
		was[0] = 1;
		x[0] = a[1];
		
		FOR(i, 1, n)
		{
			int bude = i % k;
			int chyslo = a[i + 1] - a[i];
			if (was[bude] && x[bude] != chyslo)
				ok = 0;
			x[bude] = chyslo;
			was[bude] = 1;
		}
		
		
		if (ok)
			ans.PB(k);
	}
	
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i << " ";	
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}