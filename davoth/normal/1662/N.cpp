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

const int xn = 1500 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn][xn], b[xn][xn];
pii f[xn][xn][2];
int fen[xn], ptr, tb[xn * xn];
ll ans;
vector <int> cprs;

void mofen(int pos){
	for (pos += 5; pos < xn; pos += pos & - pos)
		++ fen[pos];
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res += fen[pos];
	return res;
}
void rot(){
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			b[i][j] = a[j][n + 1 - i];
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			a[i][j] = b[i][j];
}
void solve(){
	for (int i = 1; i <= n; ++ i){
		ptr = 0, cprs.clear();
		for (int j = 1; j <= n; ++ j)
			cprs.push_back(a[i][j]);
		sort(all(cprs));
		for (int x : cprs)
			tb[x] = ++ ptr;
		for (int j = 1; j <= n; ++ j){
			int x = tb[a[i][j]];
			f[i][j][0].A = gefen(x);
			f[i][j][0].B = j - 1 - f[i][j][0].A;
			mofen(x);
		}
		fill(fen, fen + n + 10, 0);
	}
	for (int j = 1; j <= n; ++ j){
		ptr = 0, cprs.clear();
		for (int i = 1; i <= n; ++ i)
			cprs.push_back(a[i][j]);
		sort(all(cprs));
		for (int x : cprs)
			tb[x] = ++ ptr;
		for (int i = 1; i <= n; ++ i){
			int x = tb[a[i][j]];
			f[i][j][1].A = gefen(x);
			f[i][j][1].B = i - 1 - f[i][j][1].A;
			mofen(x);
		}
		fill(fen, fen + n + 10, 0);
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			ans -= 2 * f[i][j][0].A * f[i][j][1].A;
			ans += f[i][j][0].A * f[i][j][1].B;
			ans += f[i][j][0].B * f[i][j][1].A;
		}
	}
}
ll C(int x){
	return 1ll * x * (x - 1) / 2ll;
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			cin >> a[i][j];
	for (int i = 0; i < 4; ++ i)
		solve(), rot();
	ans /= 4;
	ans += 1ll * C(n) * C(n);
	cout << ans << endl;

	return 0;
}