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

const int N = 1 << 19;
int n;
LL a[N];
LL sum[2][N];

inline LL get(int id, int l, int r){
	if (l > r) return 0;
	LL res = sum[id][r];
	if (l) res -= sum[id][l - 1];
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, n) a[i + n] = a[i];
	
	if (n == 1){
		cout << a[0] << endl;
		return 0;
	}

	sum[0][0] = a[0];
	FOR(i, 1, n + n){
		FOR(j, 0, 2) sum[j][i] = sum[j][i - 1];
		sum[i & 1][i] += a[i];
	}
	
	LL ans = 0;
	FOR(i, 0, n){
		LL curr = a[i] + a[i + 1];
		curr += get((i + 3) & 1, i + 3, i - 2 + n);
		setmax(ans, curr);
	}
	
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}