#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
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
	int n,q; cin >> n >> q;
	set<int> avail;
	FOR(i,1,n+1) avail.insert(i);
	set<pii> todo;
	F0R(i,q) {
		int t,k,d; cin >> t >> k >> d;
		while (todo.size()>0 && (*todo.begin()).f <= t) {
			avail.insert((*todo.begin()).s);
			todo.erase(todo.begin());
		}
		// cout << "hi " << avail.size() << "\n";
		if (avail.size()<k) cout << "-1\n";
		else {
			int ans = 0;
			F0R(j,k) {
				todo.insert(mp(t+d,*(avail.begin())));
				// cout << "push " << t+d << " " << *(avail.begin()) << "\n";
				ans += *(avail.begin());
				avail.erase(avail.begin());
			}
			cout << ans << "\n";
		}
	}
	return 0;
}