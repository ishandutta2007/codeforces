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

vector<ll> x;
ll sum = 0, po2[400000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n; x.resize(n);
	po2[0] = 1;
	FOR(i,1,400000) po2[i] = (po2[i-1]*2) % MOD;
	F0R(i,400000) po2[i] --;
	F0R(i,n) cin >> x[i];
	sort(x.begin(),x.end());
	F0R(i,n) {
	    int a = i-1, b = n-1-i-1;
	    sum = (sum+(po2[a+1]-po2[b+1])*x[i]) % MOD;
	    while(sum<0) sum += MOD;
	}
	cout << sum;
}