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
#define int long long

int lcm = 1;

main() {
	ios_base::sync_with_stdio(0);
	int n,k; cin >> n >> k;
	F0R(i,n) {
		int z; cin >> z;
		z = __gcd(k,z);
		lcm = lcm*z/__gcd(lcm,z);
	}
	if (lcm == k) cout << "YES";
	else cout << "NO";
	return 0;
}