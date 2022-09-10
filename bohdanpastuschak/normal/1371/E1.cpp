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

const int N = 1 << 11;
int n, p;
int a[N];

inline bool f(int x){
	vector<int> cnt(n + 2, 0);
	FOR(i, 0, n){
		int k = a[i] - x + 1;
		if (k > n) return 0;
		cnt[max(1, k)]++;
	}
		
	int ans = 1;
	FOR(i, 1, n + 1){
		if (cnt[i] == 0){
			ans = 0;
		}else{
			ans = (ans * (LL) cnt[i]) % p;
			cnt[i + 1] += cnt[i] - 1;
		}			
	}
	
	return ans > 0;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> p;
	FOR(i, 0, n) cin >> a[i];
	
	vector<int> ans;
	FOR(x, 1, 2001) if (f(x)) ans.PB(x);	
	cout << SZ(ans) << endl;
	for(auto i: ans) cout << i << ' ';
	cout << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}