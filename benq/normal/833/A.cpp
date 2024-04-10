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

int n;

bool iscube(ll x) {
    ll x1 = pow(x,0.333);
    while ((x1+1)*(x1+1)*(x1+1) <= x) x1 ++;
    if (x1*x1*x1 == x) return 1;
    return 0;
}

bool solve(ll a, ll b) {
    ll g = __gcd(a,b);
    ll a1 = a/g, b1 = b/g;
    if (a1*b1 > a || a1*b1 > b) return 0;
    
    ll a2 = a1*a1*b1, b2 = a1*b1*b1;
    if (a % a2 != 0) return 0;
    return iscube(a/a2);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int a,b; cin >> a >> b;
	    if (solve(a,b)) cout <<  "Yes\n";
	    else cout << "No\n";
	}
}