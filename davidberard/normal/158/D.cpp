#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;
	cin >> N;


	ll mx = (ll) -1e18;
	vector<int> t(N);
	for(int i=0;i<N;++i)
        cin >> t[i];

	for(int i=1;i<=N/3;++i) {
		ll tmax = -1e18;
		for(int j=0;j<i;++j) {
			ll sum = 0;
			for(int k=j;k<N;k+=i) {
				sum += t[k];
			}
			//cerr << " spacing " << i << " sum " << sum << " start " << j << endl;
			tmax = max(tmax, sum);
		}
		if(N%i != 0) continue;
		mx = max(mx, tmax);
	}
	cout << mx << endl;

	return 0;
}