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

struct mat {
	double d[128][128];
	mat() {
		F0R(i,128) F0R(j,128) d[i][j] = 0;
	}
	mat operator* (const mat& B) {
		mat C;
		F0R(i,128) F0R(j,128) F0R(k,128) 
			C.d[i][j] += d[i][k]*B.d[k][j];
		return C;
	}
};

double prob[101];
mat z;
int n,x;

mat po(mat m, int p) {
	mat ans; F0R(i,128) ans.d[i][i] = 1;
	while (p) {
		if (p&1) ans = ans*m;
		m = m*m;
		p /= 2;
	}
	return ans;
}

int main() {
	cin >> n >> x;
	F0R(i,x+1) cin >> prob[i];
	F0R(i,128) F0R(j,x+1) z.d[i][i^j] = prob[j];
	z = po(z,n);
	cout << fixed << setprecision(9) << 1-z.d[0][0];
}