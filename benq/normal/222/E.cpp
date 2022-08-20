/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

ll n,m,k;

struct mat {
	ll d[53][53];
	mat() {
		F0R(i,53) F0R(j,53) d[i][j] = 0;
	}
	mat operator*(const mat& B) {
		mat C;
		F0R(i,53) F0R(j,53) F0R(k,53) 
			C.d[i][j] = (C.d[i][j]+d[i][k]*B.d[k][j]) % MOD;
		return C;
	}
};

int get(char x) {
	if ('a' <= x && x <= 'z') return x-'a';
	return x-'A'+26;
}

mat t;

mat po(mat x, ll p) {
	mat ans;
	F0R(i,53) ans.d[i][i] = 1;
	while (p) {
		if (p&1) ans = ans*x;
		x = x*x;
		p /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	
	F0R(i,m) F0R(j,m) t.d[i][j] = 1;
	F0R(i,m) t.d[m][i] = 1;
	
	F0R(i,k) {
		char x,y; cin >> x >> y;
		t.d[get(x)][get(y)] = 0;
	}
	
	mat T = po(t,n);
	ll ans = 0;
	F0R(i,m) ans = (ans+T.d[m][i]) % MOD;
	cout << ans;
}