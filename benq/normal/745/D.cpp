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

ll ans[1001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	FOR(i,1,n+1) ans[i] = MOD;
	FOR(i,1,11) {
		int cur = (1<<i);
		vi q1, q2;
		FOR(j,1,n+1) if (1 <= (j % cur) && (j % cur) <= cur/2) q1.pb(j);
		else q2.pb(j);
		if (q2.size() == 0) break;
		
		cout << q1.size() << endl;
		F0R(j,q1.size()) cout << q1[j] << " ";
		cout << endl;
		
		FOR(j,1,n+1) {
			ll res; cin >> res;
			if (!(1 <= (j % cur) && (j % cur) <= cur/2)) ans[j] = min(ans[j],res);
		}
		
		cout << q2.size() << endl;
		F0R(j,q2.size()) cout << q2[j] << " ";
		cout << endl;
		
		FOR(j,1,n+1) {
			ll res; cin >> res;
			if (1 <= (j % cur) && (j % cur) <= cur/2) ans[j] = min(ans[j],res);
		}
	}
	cout << -1 << endl;
	FOR(i,1,n+1) cout << ans[i] << " ";
	cout << endl;
}