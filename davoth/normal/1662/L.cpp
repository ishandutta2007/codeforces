//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, a[xn], t[xn], b[xn], c[xn], v;
int ptr, dp[xn], fen[xn], ans;
vector <pll> cprs;
vector <pip> vec;

void CPR(ll *A){
	ptr = 0;
	cprs.clear();
	for (int i = 0; i <= n; ++ i)
		cprs.push_back({A[i], i});
	sort(all(cprs));
	for (int i = 0; i < SZ(cprs); ++ i){
		if (!i || cprs[i].A != cprs[i - 1].A)
			++ ptr;
		A[cprs[i].B] = ptr;
	}
}
void mofen(int pos, int val, bool f = false){
	for (pos += 5; pos < xn; pos += pos & - pos){
		fen[pos] = max(fen[pos], val);
		if (f)
			fen[pos] = - inf;
	}
}
int gefen(int pos){
	int res = - inf;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res = max(res, fen[pos]);
	return res;
}
void divide(int l, int r){
	if (r - l == 1){
		++ dp[l];
		ans = max(ans, dp[l]);
		return;
	}
	int mid = l + r >> 1;
	divide(l, mid);
	
	vec.clear();
	for (int i = l; i < mid; ++ i)
		vec.push_back({a[i], {0, i}});
	for (int i = mid; i < r; ++ i)
		vec.push_back({a[i], {1, i}});
	sort(all(vec));
	for (pip X : vec){
		int ty = X.B.A, id = X.B.B;
		if (ty)
			dp[id] = max(dp[id], gefen(n - b[id]));
		else
			mofen(n - b[id], dp[id]);
	}
	for (pip X : vec)
		if (!X.B.A)
			mofen(n - b[X.B.B], 0, 1);
	
	vec.clear();
	for (int i = l; i < mid; ++ i)
		vec.push_back({n - a[i], {0, i}});
	for (int i = mid; i < r; ++ i)
		vec.push_back({n - a[i], {1, i}});
	sort(all(vec));
	for (pip X : vec){
		int ty = X.B.A, id = X.B.B;
		if (ty)
			dp[id] = max(dp[id], gefen(c[id]));
		else
			mofen(c[id], dp[id]);
	}
	for (pip X : vec)
		if (!X.B.A)
			mofen(c[X.B.B], 0, 1);
	divide(mid, r);
}

int main(){
	fast_io;

	cin >> n >> v;
	for (int i = 1; i <= n; ++ i)
		cin >> t[i], t[i] *= v, dp[i] = - inf;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		b[i] = a[i] - t[i];
		c[i] = a[i] + t[i];
	}
	CPR(a), CPR(t), CPR(c), CPR(b);
	dp[0] = - 1;
	fill(fen, fen + xn, - inf);
	divide(0, n + 1);
	cout << ans << endl;

	return 0;
}