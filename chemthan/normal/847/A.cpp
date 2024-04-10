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

int n, pre[maxn], nex[maxn];

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	For(i, 1, n) cin >> pre[i] >> nex[i];

	int cur = 0;
	For(i, 1, n) if(!pre[i]){
		pre[i] = cur;
		nex[cur] = i;
		cur = i;
		while(nex[cur]){
			int u = nex[cur];
			pre[u] = cur;
			cur = u;
		}
	}
	nex[cur] = 0;
	For(i, 1, n){
		cout << pre[i] << " " << nex[i] << endl;
	}

	return 0;
}