#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcnt(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-12
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 505

int dr[4] = {0, +1, 0, -1};
int dc[4] = {+1, 0, -1, 0};

int n, m, p, q;
string s[maxn];
ll f[maxn][maxn], a[maxn][maxn];
II que[maxn * maxn];
int size;

bool inside(int r, int c){
	return r >= 0 && r < n && c >= 0 && c < m;
}

void go(int u, int v, int number){
	size = 0;
	que[size++] = mp(u, v);
	a[u][v] = number;
	Rep(i, size){
		int r = que[i].fi, c = que[i].se;
		int add = a[r][c];
		f[r][c] += add;
		if(add < 2) continue;
		Rep(h, 4){
			int rr = r + dr[h], cc = c + dc[h];
			if(inside(rr, cc) && s[rr][cc] != '*' && a[rr][cc] == -1){
				a[rr][cc] = (add >> 1);
				que[size++] = mp(rr, cc);
			}
		}
	}
	Rep(i, size){
		int r = que[i].fi, c = que[i].se;
		a[r][c] = -1;
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p >> q;
	Rep(i, n) cin >> s[i];
	ms(f, 0); ms(a, -1);
	Rep(i, n) Rep(j, m) if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
		go(i, j, (s[i][j] - 'A' + 1) * p);
	}

	int res = 0;
	Rep(i, n) Rep(j, m) res += (f[i][j] > q);
	cout << res << endl;

	return 0;
}