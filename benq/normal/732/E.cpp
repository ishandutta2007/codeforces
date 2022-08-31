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

int a[200001], b[200001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	vector<pii> s, s1;
	set<pii> c;
	FOR(i,1,n+1) {
		int x; cin >> x;
		c.insert(mp(x,i));
	}
	FOR(i,1,m+1) {
		int x; cin >> x;
		s.pb(mp(x,i));
	}
	int cur = 0, ans = 0, u = 0;
	// cout << "t1";
	while (s.size()) {
		s1.clear();
		for (pii i: s) {
			// cout << cur << " " << i.f << " " << i.s << "\n";
			auto it = c.lb(mp(i.f,0));
			if (it == c.end()) {
				s1.pb(i);
				continue;
			}
			pii z = *it;
			if (z.f == i.f) {
				// cout << "H";
				a[i.s] = cur;
				b[z.s] = i.s;
				ans++;
				u += cur;
				c.erase(z);
			} else {
				// cout << "H";
				s1.pb(i);
			}
		}
		s = s1;
		// cout << "HI " << s.size() << "\n";
		cur++;
		s1.clear();
		for (auto i: s) if (i.f != 1) s1.pb(mp((i.f+1)/2,i.s));
		s = s1;
	}
	cout << ans << " " << u << "\n";
	FOR(i,1,m+1) cout << a[i] << " ";
	cout << "\n";
	FOR(i,1,n+1) cout << b[i] << " ";
	cout << "\n";
}