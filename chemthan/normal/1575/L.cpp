#include <bits/stdc++.h>
//#include "RNG.h"
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define linf (1ll << 60)
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-6
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 500005

int n, a[maxn], f[maxn];;
II P[maxn];

int get(int u){
	int res = 0;
	for(int i = u; i > 0; i -= i & -i){
		res = max(res, f[i]);
	}
	return res;
}

void update(int u, int gt){
	for(int i = u; i < maxn; i += i & -i) f[i] = max(f[i], gt);
}

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin >> n;
    For(i, 1, n) {
    	cin >> a[i];
    	P[i] = mp(i + n - a[i], i);
    }


    sort(P + 1, P + n + 1);

    ms(f, 0);
    int res = 0;

    update(1, 0);
    For(i, 1, n){
    	int id = P[i].se;
    	if(P[i].fi < n) continue;
    	int u = a[id];
    	int A = get(u) + 1;
//    	cout << id << " " << u << " " << A << endl;
    	res = max(res, A);
    	update(u + 1, A);
    }
    cout << res << endl;

}

int main(){
  solve();

  return 0;
}