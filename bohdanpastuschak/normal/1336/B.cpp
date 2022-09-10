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

const int N = 1 << 17;
int n[3];
LL A[3][N];

inline LL sq(LL x, LL y)
{
	return (x - y) * (x - y);
}

inline LL get(vector<int> vec)
{
	LL ans = 0;
	FOR(i, 0, 3) FOR(j, 0, i) ans += sq(A[i][vec[i]], A[j][vec[j]]);
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	int t;
	cin >> t;
	while(t--)
	{
		FOR(i, 0, 3) cin >> n[i];
		FOR(i, 0, 3) FOR(j, 0, n[i])
			cin >> A[i][j];
		FOR(i, 0, 3)
			sort(A[i], A[i] + n[i]);
		
		LL ans = 3 * LINF;
		FOR(mid, 0, 3) FOR(i, 0, n[mid])
		{
			int val = A[mid][i];
			
			int x = -1, y = -1;
			FOR(it, 0, 3) if (it != mid)
			{
				if (x == -1) x = it;
				else y = it;
			}
			
			auto it11 = lower_bound(A[x], A[x] + n[x], val) - A[x];
			auto it12 = upper_bound(A[x], A[x] + n[x], val) - A[x] - 1;
			
			auto it21 = lower_bound(A[y], A[y] + n[y], val) - A[y];
			auto it22 = upper_bound(A[y], A[y] + n[y], val) - A[y] - 1;
		
			VI ids = {0, 0, 0};
			ids[mid] = i;			
			
			if (it12 >= 0 && it21 < n[y])
			{
				ids[x] = it12;
				ids[y] = it21;
				setmin(ans, get(ids));
			}
			
			if (it11 < n[x] && it22 >= 0)
			{
				ids[x] = it11;
				ids[y] = it22;
				setmin(ans, get(ids));
			}
		}		
		
		cout << ans << endl;
	}
	
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}