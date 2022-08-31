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

ll n,k;
double l,v1,v2; 
double t = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> l >> v1 >> v2 >> k;
	ll tmp = (n+k-1)/k;
	t = tmp+(tmp-1)*(v2-v1)/(v2+v1);
	double a = (v2+(t-1)*v1)/t;
	cout << fixed << setprecision(9) << l/a;
}