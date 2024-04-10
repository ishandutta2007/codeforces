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

#define maxn 500005

int n, T, a[maxn], f[maxn];
vector<int> V;

int get(int u){
	int res = 0;
	for(int i = u; i > 0; i -= i & -i) res += f[i];
	return res;
}

void update(int u){
	for(int i = u; i < maxn; i += i & -i) f[i]++;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> T;
	For(i, 1, n){
		cin >> a[i];
		V.pb(a[i] - i);
	}
	For(i, 2, n + 1){
		V.pb(T - i);
	}

	V.pb(-inf);
	sort(all(V));

	int res = 0;
	For(i, 1, n){
		int u = lower_bound(all(V), a[i] - i) - V.begin();
//		cout << u << endl;
		update(u);
		if(T - i - 1 >= 0){
			u = lower_bound(all(V), T - i - 1) - V.begin();
//			cout << u << " " << get(u) << endl;
			res = max(res, get(u));
		}
	}
	cout << res << endl;

	return 0;
}