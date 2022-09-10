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

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		vector<int> ans(n, 0);
		FOR(i, 0, n)
		{
			int x;
			cin >> x;
			FOR(j, 0, SZ(p))
				if (x % p[j] == 0)
				{
					ans[i] = j + 1;
					break;
				}
				
			assert(ans[i]);
		}
		
		map<int, int> mp;
		int id = 1;
		FOR(i, 0, n)
		{
			if (mp.count(ans[i])) ans[i] = mp[ans[i]];
			else 
			{
				mp[ans[i]] = id;
				ans[i] = id;
				id++;
			}
		}
		
		cout << id - 1 << endl;
		FOR(i, 0, n) cout << ans[i] << ' ';
		cout << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}