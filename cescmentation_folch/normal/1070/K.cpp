#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;


int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k, n;
	cin >> n >> k;
	ll S[n];
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
		sum += S[i];
	}
	if (sum%k) {
		cout << "No\n";
		return 0;
	}
	ll s = sum/k;
	int res[k];
	int i = 0;
	for (int j = 0; j < k; ++j) {
		ll suma = 0;
		int cont = 0;
		while (suma < s) {
			++cont;
			suma += S[i++];
		}
		if (suma > s) {
			cout << "No\n";
			return 0;
		}
		res[j] = cont;
	}
	cout << "Yes\n";
	for (int j = 0; j < k; ++j) {
		if (j) cout << ' ';
		cout << res[j];
	}
	cout << '\n';

}