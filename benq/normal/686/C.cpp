#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
#define int long long

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll ans = 0;
ll n,m,n1,m1,n2,m2;

void add(vi z, int used) {
	if (z.size()<(n2+m2)) {
		F0R(i,7) if ((used & (1<<i)) == 0) {
			vi z1 = z;
			z1.pb(i);
			add(z1,used|(1<<i));
		}
	} else {
		ll n3=0,m3=0;
		ll c1 = 1, c2 = 1;
		for (int i = n2-1; i >= 0; --i) {
			n3 += c1*z[i];
			c1 *= 7;
		}
		for (int i = z.size()-1; i >= n2; --i) {
			m3 += c2*z[i];
			c2 *= 7;
		}
		if (n3 < n && m3 < m) ans++;
	}
}

main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	n1 = n-1, m1 = m-1;
	if (n == 1) n2 = 1;
	else while (n1 > 0) n1 /= 7, n2++;
	if (m == 1) m2 = 1;
	else while (m1 > 0) m1 /= 7, m2++;
	
	if (n2+m2>7) {
		cout << 0;
		return 0;
	}
	vi g;
	add(g,0);
	cout << ans;
	return 0;
}