#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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

const int N = 1 << 10;
int n, k;
LL a[N];

bool solve()
{
	cin >> n >> k;
	set<int> s;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n)
	{
		LL x = a[i];
		FOR(it, 0, 60)
		{
			int rem = x % k;
			if (rem == 0)
				x /= k;
			else if (rem == 1)
				{
					if (s.count(it)) return false;
					s.insert(it);
					x /= k;
				}
				else return false;
		}
	}		
			
	return true;		
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--)
		cout << (solve() ? "YES\n" : "NO\n");
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}