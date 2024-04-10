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

const int MAX = 1 << 20;
int n, m;
int a[MAX];
int mp[MAX];
LL cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> a[i];
		if (a[i] < MAX)
			mp[a[i]]++;
	}
	
	FOR(i, 1, m + 1)
		for(int j = 1; j * i <= m; ++j)
			cnt[j * i] += mp[i];
	
	LL mx = -1;
	FOR(i, 1, m + 1)
		mx = max(mx, cnt[i]);
	
	int ds = 0;
	FOR(i, 1, m + 1)
		if (cnt[i] == mx)
		{
			ds = i;
			break;
		}
	
	cout << ds << " " <<  mx << endl;
	FOR(i, 0, n)
		if (ds % a[i] == 0)
			cout << i + 1 << " ";

	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}