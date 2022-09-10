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
vector<PII> ans;
bool used[MAX];
int pr[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	FOR(i, 2, MAX)
		pr[i] = i;
	
	FOR(i, 2, MAX)
		if (pr[i] == i)
			for(LL j = i * (LL) i; j < MAX; j += i)
				if (pr[j] == j)
					pr[j] = i;
	
	
	int n;
	cin >> n;

	RFOR(p, n + 1, 2)
	{
		if (pr[p] != p)
			continue;
		
		VI d;
		for(int j = p; j <= n; j += p)
			if (!used[j])
				d.PB(j);
		
		if (SZ(d) & 1)
		{
			for(auto& i: d)
				if (pr[i] < p)
				{
					swap(i, d.back());
					break;
				}
			d.pop_back();
		}		
		
		for(int i = 0; i < SZ(d); i += 2)
		{
			ans.PB(MP(d[i], d[i + 1]));
			used[d[i]] = used[d[i + 1]] = 1;
		}
	}
	
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i.X << ' ' << i.Y << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}