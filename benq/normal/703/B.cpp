#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll s = 0, s1 = 0, ans = 0;
vi c;
bool cap[100000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k; cin >> n >> k;
	c.resize(n);
	F0R(i,n) {
		cin >> c[i];
		s += c[i];
	}
	F0R(i,k) {
		int d; cin >> d;
		cap[d-1] = 1;
		s1 += c[d-1];
	}
	F0R(i,n) {
		if (cap[i]) ans += c[i]*(s-c[i]);
		else {
			ans += c[i]*s1;
			if (i == 0) {
				if (!cap[n-1]) ans += c[0]*c[n-1];
			} else {
				if (!cap[i-1]) ans += c[i]*c[i-1];
			}
			if (i == (n-1)) {
				if (!cap[0]) ans += c[0]*c[n-1];
			} else {
				if (!cap[i+1]) ans += c[i]*c[i+1];
			}
		}
	}
	cout << ans/2;
}