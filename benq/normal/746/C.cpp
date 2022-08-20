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
	int s, x1, x2;
	cin >> s >> x1 >> x2;
	int t1, t2; cin >> t1 >> t2;
	int p, d; cin >> p >> d;
	if (t2 <= t1) {
		cout << t2*abs(x1-x2);
		return 0;
	}
	if (x1 >= x2) {
		x1 = s-x1;
		x2 = s-x2;
		p = s-p;
		d = -d;
	}
	int ans = abs(x1-x2)*t2;
	if (p >= x2) { // opposite sides
		if (d == 1) ans = min(ans,t1*(s-p+s+x2));
		else ans = min(ans,t1*(p+x2));
	} else { // both are on the same side
		if (p > x1) { 
			if (d == 1) ans = min(ans,t1*(s-p+s+x2));
			else ans = min(ans,t1*(x2+p));
		} else {
			if (d == 1) ans = min(ans,t1*(x2-p));
			else ans = min(ans,t1*(x2+p));
		}
	}
	cout << ans;
}