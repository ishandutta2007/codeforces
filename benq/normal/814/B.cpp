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

vi ans, a, b;
int n; 

bool test(vi z) {
	map<int,int> m;
	for (int i: z) {
		if (m[i] > 0) return 0;
		m[i] = 1;
	}	
	int co1 = 0, co2 = 0;
	F0R(i,n) {
		if (z[i] != a[i]) co1++;
		if (z[i] != b[i]) co2 ++;
	}
	if (co1 != 1 || co2 != 1) return 0;
	return 1;
}

void print(vi x) {
	F0R(i,n) cout << x[i] << " ";	
}

int main() {
	cin >> n; ans.resize(n); a.resize(n), b.resize(n);
	F0R(i,n) cin >> a[i];
	F0R(i,n) cin >> b[i];
	
	int co = 0;
	F0R(i,n) {
		if (a[i] == b[i]) ans[i] = a[i];
		else if (co == 0) {
			co++;
			ans[i] = a[i];
		} else ans[i] = b[i];
	}
	if (test(ans)) {
		print(ans);
		return 0;
	}
	co = 0;
	F0R(i,n) {
		if (a[i] == b[i]) ans[i] = a[i];
		else if (co == 0) {
			co++;
			ans[i] = b[i];
		} else ans[i] = a[i];
	}
	if (test(ans)) {
		print(ans);
		return 0;
	}
	set<int> left; FOR(i,1,n+1) left.insert(i);
	F0R(i,n) if (a[i] == b[i]) left.erase(a[i]);
	int z = *left.begin();
	F0R(i,n) {
		if (a[i] == b[i]) ans[i] = a[i];
		else ans[i] = z;
	}
	print(ans);
}