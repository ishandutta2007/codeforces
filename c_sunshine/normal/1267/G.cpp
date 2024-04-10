#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#define ook order_of_key
#define fbo find_by_order
 
using namespace std;
 
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
 
#define f first
#define s second
#define all(x) begin(x), end(x)
#define rsz resize
 
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double ld;
 
template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
typedef string str;
 
const int MX = 2e5+5;
 
int n,x,c[MX];
ld dp[16];
 
void brute() {
	FOR(i,1,1<<n) {
		vi v;
		F0R(j,n) if (i&(1<<j)) {
			dp[i] += c[j];
			v.pb(j);
		}
		ld sum = 0;
		trav(t,v) sum += dp[i^(1<<t)];
		sum += (ld)x*(sz(v)+n)/2;
		ckmin(dp[i],sum/sz(v));
	}
}

typedef array<array<ld,10001>,101> T;
 
ld expec[101];
ld tot, ans;
int sum = 0;
 
void ad(T& wei, int t) {
	R0F(i,n) F0R(j,10001-t) {
		wei[i+1][j+t] += wei[i][j]*(i+1)/(n-i);
	}
}
 
/*void del(int t) {
	F0R(i,n) F0R(j,10001) WEI[i][j] = wei[i][j];
	F0R(i,n) R0F(j,10001-t) {
		WEI[i+1][j+t] -= WEI[i][j]*(i+1)/(n-i);
	}
	F0R(i,n) F0R(j,10001) if (WEI[i][j] < 0) {
		cout << "WUT " << t << " " << i << " " << j << " " << WEI[i][j] << "\n";
	}
}*/
 
void test(T& wei, int t) {
	// sum <= x*n after, sum > x*n before
	F0R(i,n) F0R(j,10001) {
		int a = 2*(sum-j)-x*(n-i);
		int b = 2*(sum-j-t)-x*(n-i-1);
		if (a >= x*n && b < x*n) {
			ld p = wei[i][j]/(n-i);
			tot += p; ans += p*(expec[i+1]+sum-j-t);
		}
		// sum of 2*c_i-x over
	}
}
 
void divi(T t, int l, int r) {
	if (l == r) {
		test(t,c[l]);
		return;
	}
	int m = (l+r)/2;
	T a = t; FOR(i,m+1,r+1) ad(a,c[i]); 
	divi(a,l,m);
	a = t; FOR(i,l,m+1) ad(a,c[i]); 
	divi(a,m+1,r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	n = 100; x = 1;
	cin >> n >> x;	
	F0R(i,n) {
		c[i] = 1+rand()%100; 
		cin >> c[i];
		sum += c[i];
	}
	FOR(i,1,n+1) {
		expec[i] = expec[i-1]+(ld)x/2+(ld)x*n/(2*(n+1-i));
	}
	T wei; wei[0][0] = 1;
	divi(wei,0,n-1);
	// exit(0);
	/*F0R(i,n) ad(c[i]);
	F0R(i,n) {
		del(c[i]);
		test(c[i]);
	}*/
	// compare sum of c_i-x/2 and x*n/2
	// compare sum of 2*c_i-x and x*n
	// if first is less than you should just buy all remaining
	//assert(0.999 < tot && tot < 1.001);
	// cout << "HA " << tot << "\n";
	cout << fixed << setprecision(12) << ans/tot << "\n";
}