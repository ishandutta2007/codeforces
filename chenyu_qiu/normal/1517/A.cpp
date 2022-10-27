#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iterator>
using namespace std;
typedef long long ll;
template<class T>T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
#define setpre(a) cout<<fixed<<setprecision(a)
#define FOR(i,n) for(int i=0;i<n;i++)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define bug cout<<"!!!\n";

void solve() {
	ll n;
	cin >> n;
	if (n < 2050||((n%2050)>0)) {
		cout << "-1\n";
	}
	else {
		ll m, ans = 0;
		m = n / 2050;
		while (m) {
			ans += m % 10;
			m /= 10;
		}
		cout << ans << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}