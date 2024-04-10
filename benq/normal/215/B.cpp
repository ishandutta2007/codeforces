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

int n, m, k;
double A, B, p2;
vi x, y, z;
double mx = 0;

double get(int r1, int p1) {
    return sqrt(B*p1*r1*r1/(A*p2+B*p1));    
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; x.resize(n);
	F0R(i,n) cin >> x[i];
	
	cin >> m; y.resize(m);
	F0R(i,m) cin >> y[i];
	
	cin >> k; z.resize(k);
	F0R(i,k) cin >> z[i];
	p2 = z[0];
	FOR(i,1,k) p2 = min(p2,(double)z[i]);
	
	cin >> A >> B;
	F0R(i,n) F0R(j,m) {
	    mx = max(mx,get(x[i],y[j]));
	}
	cout << fixed << setprecision(9) << mx;
}