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

ll n,m,n1,m1,g,inv;

ll solve(int x, int y) {
    ll dif = y-x;
    if (dif % (2*g) != 0) return LLONG_MAX;
    dif /= (2*g); dif %= m1;
    while (dif<0) dif += m1;
    if (dif == 0) return x;
    ll z = inv*dif % m1;
    ll ans = 2*n*z+x;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	g = __gcd(n,m);
	n1 = n/g, m1 = m/g;
	F0R(i,m1) if (((ll)n1*i % m1) == 1) inv = i;
	int k; cin >> k;
	F0R(i,k) {
	    int x,y; cin >> x >> y;
	    ll ans = LLONG_MAX;
	    ans = min(min(solve(x,y),solve(x,2*m-y)),min(solve(2*n-x,y),solve(2*n-x,2*m-y)));
	    if (ans == LLONG_MAX) cout << -1 << "\n";
	    else cout << ans << "\n";
	}
}