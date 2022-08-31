#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

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
	int n,ans=0; cin >> n;
	vi mx;
	F0R(i,n) {
		int k; cin >> k;
		while (mx.size() && mx[mx.size()-1] < k) {
			ans = max(ans,k^mx[mx.size()-1]);
			mx.erase(mx.end()-1);
		}
		if (mx.size()) ans = max(ans,k^mx[mx.size()-1]);
		mx.pb(k);
	}
	cout << ans;
}