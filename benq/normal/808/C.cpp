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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,w,sum=0; cin >> n >> w;
	
	vector<pii> a(n);
	vi b(n);
	F0R(i,n) {
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	// restore
	F0Rd(i,n) {
		b[i] = (a[i].f+1)/2;
		if (i != n-1) b[i] = max(b[i],b[i+1]);
		if (b[i] > a[i].f) {
			cout << -1;
			return 0;
		}
		sum += b[i];
	}
	if (sum>w) {
		cout << -1;
		return 0;
	}
	F0R(i,n) {
		while (sum<w) {
			int mn = a[i].f;
			if (i) mn = min(mn,b[i-1]);
			if (b[i] < mn) b[i] ++, sum ++;
			else break;
		}
	}
	if (sum<w) {
		cout << -1;
		return 0;
	}
	int ans[100];
	F0R(i,n) ans[a[i].s] = b[i];
	F0R(i,n) cout << ans[i] << " ";
}