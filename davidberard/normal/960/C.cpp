#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll X, d; cin  >> X >> d;
	ll dist = d*2+2;

	vector<ll> v;
	ll offset = 1;
	for(ll i=31;i>0;--i) {
		while(X >= ((1<<i)-1)) {
			//cerr << "X = " << X << " vs " << ((1<<i)-1) << endl;
			for(ll j=0;j<i;++j) {
				v.push_back(offset);//+offset);
			}
			offset += dist;
			X -= (((ll) 1<<i)-1);
		}
	}

	cout << v.size() << endl;
	for(ll& ii : v) {
		cout << ii << " ";
	}
	cout << endl;
		
	return 0;
}