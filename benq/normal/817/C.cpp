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

ll n,s,ans; 

ll po(int x) {
	ll p = 1;
	F0R(i,x) p *= 10;
	return p;
}

void search(int numdigits, ll curval, ll curint) {
	if (curval >= s) {
		ans += (min(curint+po(numdigits)-1,n)-curint+1);
		return;
	}
	ll mx = curval;
	F0R(i,numdigits) mx += (po(i)-1)*9;
	if (mx < s) return;
	F0R(i,10) {
		ll nint = curint+po(numdigits-1)*i;
		if (nint > n) continue;
		search(numdigits-1,curval+(po(numdigits-1)-1)*i,nint);
	}
}

int main() {
	// sum >= s, num <= n
	cin >> n >> s;
	search(18,0,0);
	if (n == po(18) && (po(18)-1) >= s) ans++;
	cout << ans;
}