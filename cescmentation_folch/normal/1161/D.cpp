#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pi;

const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin >> a;
	int n = a.size();
	reverse(a.begin(), a.end());
	ll res = 0;
	if (a[0] == '1') {
		cout << 0 << endl;
		return 0;
	} else a[0] = '0';
	int mig1 = -1;
	if (n%2) mig1 = n/2 + 1;
	//cerr << "mig " << mig1 << endl;
	for (int i = 1; i < n; ++i) {
		//cerr << "cosa " << i << endl;
		ll pos = 1;
		vi V(n,0);
		int mig2 = -1;
		if (i%2) mig2 = i/2 + 1;
		for (int j = n; j > i; --j) {
			if (V[j-1]) continue;
			//cerr << "anem " << j << endl;
			V[j-1] = 1;
			pi t(0,0);
			if (a[j-1] == '1' or a[j-1] == '?') t.first = 1;
			if (a[j-1] == '0' or a[j-1] == '?') t.second = 1;
			int k = n - j + 1;
			bool coss = true;
			while (k <= i and k != mig1) {
				if (a[k-1] == '1') {
					swap(t.first, t.second);
				} else if (a[k-1] == '?') {
					ll kt = (t.first + t.second)%mod;
					t = pi(kt,kt);
				}
				k = i - k + 1;
				if (k == mig2) {
					coss = false;
					break;
				}
				if (a[k-1] == '1') {
					swap(t.first, t.second);
				} else if (a[k-1] == '?') {
					ll kt = (t.first + t.second)%mod;
					t = pi(kt,kt);
				}
				k = n - k + 1;
			}
			//cerr << "arriba " << k << endl;
			if (k > i and coss) {
				if (a[k-1] == '1') pos = (pos*t.first)%mod;
				else if (a[k-1] == '0') pos = (pos*t.second)%mod;
				else pos = (pos*(t.first + t.second))%mod;
				V[k-1] = 1;
			} else pos = (pos*(t.first + t.second))%mod;
		}
		//cerr << pos << endl;
		res = (res + pos)%mod;
	}
	cout << res << endl;
}