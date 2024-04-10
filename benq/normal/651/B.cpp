#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int n, ans = 0;
	vi a, alt;
	cin >> n;
	F0R(i,n) {
		int x;
		cin >> x;
		a.pb(x);
	}
	sort(a.begin(), a.end());
	F0Rd(i,n-1) {
		if (a[i] == a[i+1]) {
			alt.pb(a[i]);
			a.erase(a.begin()+i);
		}
	}
	
	ans += (a.size()-1);
	while (alt.size()) {
		a.clear();
		F0R(i,alt.size()) a.pb(alt[i]);
		alt.clear();
		F0Rd(i,a.size()-1) {
			if (a[i] == a[i+1]) {
				alt.pb(a[i]);
				a.erase(a.begin()+i);
			}
		}
		ans += (a.size()-1);
	}
	cout << ans;
	return 0;
}