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

int to_int(string s)
{
	int res = 0;
	for(auto i: s) res = res * 10 + i - '0';
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	/*FOR(n, 1, 1000) FOR(m, 1, 1000)
	{
		string s = to_string(n) + to_string(m);
		bool raz = n * m + n + m == to_int(s);
		bool dwa = (m == 9 || m == 99 || m == 999);
		
		assert(raz == dwa);
	}*/
	
	VI A;
	int pw = 1;
	FOR(i, 1, 10)
	{
		pw *= 10;
		A.PB(pw - 1);
	}
	
	for(auto i: A) cerr << i << endl;
	
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		LL ans = 0;
		for(auto i: A) ans += i <= b;
		
		ans *= a;
		cout << ans << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}