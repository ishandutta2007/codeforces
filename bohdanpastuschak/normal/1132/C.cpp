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

const int MAX = 5000 + 7;
int n, q;
PII a[MAX];
int cnt[MAX];
VI tut[MAX];
int zle[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> q;
	FOR(i, 0, q)
		cin >> a[i].X >> a[i].Y;
	
	sort(a, a + q);
	FOR(i, 0, q)
		FOR(j, a[i].X, a[i].Y + 1)
			tut[j].PB(i);
	
	int ans = 0;
	FOR(i, 0, q)
	{
		int curr = 0;
		FILL(cnt, 0);
		FILL(zle, 0);
		
		FOR(j, 0, q)
			if (i != j)
				cnt[a[j].Y + 1]--, cnt[a[j].X]++;
		FOR(j, 1, MAX)
			cnt[j] += cnt[j - 1];
		
		FOR(j, 1, n + 1)
			curr += cnt[j] > 0;
		
		FOR(j, 1, n + 1)
			if (cnt[j] == 1)
			{
				if (SZ(tut[j]) == 1)
					zle[tut[j][0]]++;
				else
				{
					assert(SZ(tut[j]) == 2);
					int ptr = 0;
					if (tut[j][0] == i)
						++ptr;
					zle[tut[j][ptr]]++;
				}
			}
		
		int mn = n + 1;
		FOR(j, 0, q)
			if (i != j)
				mn = min(mn, zle[j]);
		curr -= mn;
		ans = max(ans, curr);
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}