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
ll ans = 0, mn[1000000], a[1000000];

void divi(int l, int r) {
	if (l == r) {
		ans += a[l];
		return;
	}
	int m = (l+r)/2;
	int l1 = m, r1 = m+1;
	mn[l1] = a[l1], mn[r1] = a[r1];
	ans += min(mn[l1],mn[r1]);
	
	for (int i = m-1; i >= l; --i) mn[i] = min(mn[i+1],a[i]);
	for (int i = m+2; i <= r; ++i) mn[i] = min(mn[i-1],a[i]);
	
	while (l<l1 || r1<r) {
		if (l == l1) {
			r1++;
			ans += (m+1-l1)*min(mn[l1],mn[r1]);
		} else if (r == r1) {
			l1 --;	
			ans += (r1-m)*min(mn[l1],mn[r1]);
		} else {
			if (mn[l1-1] <= mn[r1+1]) {
				r1++;
				ans += (m+1-l1)*min(mn[l1],mn[r1]);
			} else {
				l1 --;	
				ans += (r1-m)*min(mn[l1],mn[r1]);
			}
		}
	}
	divi(l,m);
	divi(m+1,r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	F0R(i,n) cin >> a[i];
	divi(0,n-1);
	F0R(i,n) a[i] = -a[i];
	divi(0,n-1);
	cout << -ans;
}