#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

const int MOD = 1000000007;
double PI = 4*atan(1);

int q;
map<ll,ll> cost;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> q;
	F0R(i,q) {
		ll z,v,u,w;
		cin >> z;
		if (z == 1) {
            cin >> v >> u >> w;
			while (v != u) {
				if (v>u) {
					cost[v] += w;
					v /= 2;
				} else {
					cost[u] += w;
					u /= 2;
				}
			}
		} else {
		    cin >> v >> u;
			ll ans = 0;
			while (v != u) {
				if (v>u) {
					ans += cost[v];
					v /= 2;
				} else {
					ans += cost[u];
					u /= 2;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}