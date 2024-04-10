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

const int N = 1 << 17;
int n;
int a[N];
set<PII> s;
int cnt[N];

bool ok()
{
	if (SZ(s) == 1)
		return 1;
		
	auto it = s.begin();
	PII first = *it;
	++it;
	PII second = *it;
	
	auto it2 = s.end();
	--it2;
	PII last = *it2;
	--it2;
	PII prelast = *it2;
	
	if (first.X == 1 && second.X == last.X)
		return 1;
	if (first.X == prelast.X && last.X == first.X + 1)
		return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	int ans = 0;
	FOR(i, 0, n)
	{
		s.erase(MP(cnt[a[i]], a[i]));
		cnt[a[i]]++;
		s.insert(MP(cnt[a[i]], a[i]));
		if (ok())	
			ans = i;
	}
	
	cout << ans + 1 << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}