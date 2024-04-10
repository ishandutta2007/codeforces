#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int tpoww[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int lgten(int val) {
	for(int i=9;i>=0;--i) {
		if(val >= tpoww[i]) return i;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;

	cin >> N;

	ll maxx = 2*N;

	int nines = lgten(maxx);
	int tpow = tpoww[nines];
	ll goal = (ll) (2*N/tpow) * tpow;
	goal--;
	ll tgoal = goal%tpow;
	ll bot = 1;
	////cerr << " NINES " << nines << " GOAL " << goal << " BOT " << bot << endl;
	//cerr << " GOAL " << goal << " TPOW " << tpow << endl;

	if(N < 5) {
		cout << N*(N-1)/2 << endl;
	}
	else {
		ll amt = 0;
		for(;tgoal <= goal && bot < N;tgoal += tpow) {
			//cerr << "TGOAL " << tgoal << endl;
			int g = max((ll) 1, tgoal-N);
			amt += tgoal/2-g+1;
			//cerr << "  Adding " << tgoal/2-g+1 << "(g = " << g << ")" << endl;
		}

		cout << amt << endl;
	}
	

	return 0;
}