#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	ll stairs = t1 * abs(x - y);
	ll elev = t2 * abs(z - x) + t2 * abs(y-x) + 3 * t3;
	if(elev <= stairs) cout << "YES\n";
	else cout << "NO\n";

}