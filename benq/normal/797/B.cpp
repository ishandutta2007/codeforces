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

vi eve,odd;
int ans = 0, n;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int x; cin >> x;
	    if (x % 2 == 0) eve.pb(x);
	    else odd.pb(x);
	}
	for (int i: eve) if (i>0) ans += i;
	sort(odd.begin(),odd.end());
	reverse(odd.begin(),odd.end());
	ans += odd[0];
	FOR(i,1,odd.size()) {
	    if (2*i<odd.size() && odd[2*i]+odd[2*i-1]>0) ans += odd[2*i]+odd[2*i-1];
	    else break;
	}
	cout << ans;
}