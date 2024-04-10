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
	int n,m, c = 0, c1=0;
	vi b, ans;
	cin >> n >> m;
	F0R(i,n) {
		int k;
		cin >> k;
		b.pb(k);
	}
	sort(b.begin(),b.end());
	c = b[c1];
	for(int i = 1; ; ++i) {
		if (i == c) {
			if (c1<n-1)c1++;
			c = b[c1];
		} else {
			m -= i;
			if (m >= 0) ans.pb(i);
			else break;
		}
	}
	cout << ans.size() << endl;
	F0R(i,ans.size()) cout << ans[i] << " ";
	return 0;
}