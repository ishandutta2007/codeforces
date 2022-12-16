#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N; int k1, k2; cin >> k1 >> k2;
	int K = k1+k2;
	vector<int> A(N), B(N);
	for(int& ii: A) cin >> ii;
	for(int& ii: B) cin >> ii;
	priority_queue<int> pq;
	for(int i = 0;i<A.size();++i) {
		pq.push(abs(A[i]-B[i]));
	}
	int cnt = 0;
	//cerr << "pq.top() == " << pq.top() << endl;
	for(cnt=0;cnt<K && pq.top() != 0;++cnt) {
		//cerr << ".." << endl;
		int v = pq.top();
		pq.pop();
		pq.push(v-1);
	}
	//cerr << "FINISH LOOP WITH " << cnt << " OF " << K << endl;
	ll ans = 0;
	ans += (K-cnt)%2;

	while(!pq.empty()) {
		ans += (ll) pq.top()*pq.top(); pq.pop();
	}

	cout << ans << endl;

	
	return 0;
}