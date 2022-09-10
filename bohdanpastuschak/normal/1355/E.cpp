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
int h[N];
LL s[N];

inline LL get_sum(int l, int r){
	if (l > r){
		return 0;
	}
	LL res = s[r];
	if (l) res -= s[l - 1];
	return res;
}

int n, a, r, m;

LL solve(int x){
	LL cnt_more = (h + n) - upper_bound(h, h + n, x);
	LL cnt_less = lower_bound(h, h + n, x) - h;
	LL sum_more = get_sum(n - cnt_more, n - 1) - x * cnt_more;
	LL sum_less = x * cnt_less - get_sum(0, cnt_less - 1);
	
	if (sum_less >= sum_more){
		return m * sum_more + a * (sum_less - sum_more);
	}else{
		return m * sum_less + r * (sum_more - sum_less);
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> a >> r >> m;
	setmin(m, a + r);
	FOR(i, 0, n) cin >> h[i];
	sort(h, h + n);
	s[0] = h[0];
	FOR(i, 1, n) s[i] = s[i - 1] + h[i];
	
	LL ans = LINF;
	FOR(i, 0, n){
		setmin(ans, solve(h[i]));
	}
	
	int L = 0, R = INF, m1, m2;
	while(R - L > 3){
		m1 = L + (R - L) / 3;
		m2 = R - (R - L) / 3;
		LL v1 = solve(m1);
		setmin(ans, v1);
		LL v2 = solve(m2);
		setmin(ans, v2);
		if (v1 > v2){
			L = m1;
		}else{
			R = m2;
		}
	}
	
	FOR(i, L, R + 1){
		setmin(ans, solve(i));
	}
	
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}