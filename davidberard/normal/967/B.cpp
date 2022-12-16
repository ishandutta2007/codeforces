// David Berard
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	priority_queue<ll> pq;
	ll mine;
	ll S;
	ll N, A, B;
	cin >> N;
	cin >> A;
	cin >> B;
	cin >> mine;
	S = mine;
	for(ll i=1;i<N;++i) {
		ll vv; cin >> vv;
		pq.push(vv);
		S += vv;
	}
	int amt = 0;
	while(A*mine/S < B) {
		S -= pq.top(); pq.pop();
		++ amt;
	}
	cout << amt << endl;

	
	return 0;
}