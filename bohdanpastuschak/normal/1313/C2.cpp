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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 19;
int n;
int a[N];
int best = -1;
LL ans = 0;
int res[N];
LL cost[N][2];
LL C[N];

inline LL check(int i)
{
	LL tut = a[i];
	int last = a[i];
	res[i] = last;
	RFOR(j, i, 0)
	{
		setmin(last, a[j]);
		tut += last;
		res[j] = last;
	}
	
	last = a[i];
	FOR(j, i + 1, n)
	{
		setmin(last, a[j]);
		tut += last;
		res[j] = last;
	}
	
	if (tut > ans)
	{
		ans = tut;
		best = i;
	}
	
	return tut;
}

void calc(int id)
{
	stack<pair<int, int>> st;
	st.push({0, n});
	RFOR(i, n, 0)
	{
		while(st.top().X > a[i]) st.pop();
		int nxt_less = st.top().Y;
		st.push({a[i], i});
		LL val = (nxt_less - i) * (LL) a[i];
		cost[i][id] = cost[nxt_less][id] + val;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	
	FOR(it, 0, 2)
	{
		calc(it);
		reverse(a, a + n);
	}
	
	FOR(i, 0, n >> 1)
		swap(cost[i][1], cost[n - 1 - i][1]);
	
	FOR(i, 0, n) C[i] = cost[i][0] + cost[i][1] - a[i];
	int mn = 0;
	FOR(i, 0, n) if (C[i] > C[mn]) mn = i;
	check(mn);
	
	/*FOR(i, 0, n) 
	{
		FOR(j, 0, 2) cout << cost[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	*/
	/*LL A = 0;
	FOR(i, 0, n) A += res[i];
	cout << A << endl;
	return 0;*/
	
	FOR(i, 0, n) cout << res[i] << ' ';
	cout << endl;
	
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}