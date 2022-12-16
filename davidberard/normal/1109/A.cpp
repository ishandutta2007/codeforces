#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	map<ll, ll> mpe, mpo;

	int N;
	cin >> N;
	int lst = 0;
	mpe[0]++;
	for(int i=1;i<=N;++i) {
		int a;
		cin >> a;
		lst = lst^a;
		if(i&1) {
			mpo[lst]++;
		} else {
			mpe[lst]++;
		}
	}
	ll ans = 0;
	for(auto& pp : mpe) {
		ans += pp.second*(pp.second-1)/2;
	}
	for(auto& pp : mpo) {
		ans += pp.second*(pp.second-1)/2;
	}
	cout << ans << endl;

	return 0;
}