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
	ll m,n;
	cin >> n >> m;
	m--;
	vi ans(n);
	int low = 0, high = n-1;
	FOR(i,1,n+1) {
		ll temp = 1;
		F0R(j,n-i-1) temp *= 2;
		if (m >= temp) {
			m -= temp;
			ans[high--] = i;
		} else ans[low++] = i;
	}
	F0R(i,n) cout << ans[i] << ' ';
}