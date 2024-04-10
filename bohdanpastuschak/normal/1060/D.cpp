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

const int MAX = 100000 + 7;
int n; 
int l[MAX];
int r[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n;
	LL ans = n;
	FOR(i, 0, n)
	{
		cin >> l[i] >> r[i];
		ans += l[i] + r[i];
	}
	
	LL s1 = 0, s2 = 0;
	
	multiset<int> R;
	FOR(i, 0, n)
		R.insert(r[i]);
	
	sort(l, l + n);
	RFOR(i, n, 0)
	{
		auto it = R.lower_bound(l[i]);
		if (it == R.end())
			--it;
		
		s1 += min(l[i], *it);
		R.erase(it);
	}	
	
	
	multiset<int> L;
	FOR(i, 0, n)
		L.insert(l[i]);
	
	sort(r, r + n);
	RFOR(i, n, 0)
	{
		auto it = L.lower_bound(r[i]);
		if (it == L.end())
			--it;
		
		s2 += min(r[i], *it);
		L.erase(it);
	}	
	
//	assert(s1 == s2);
	s1 = max(s1, s2);
	ans -= s1;	
	cout << ans << endl; 
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}