#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, D;
	cin >> N;
	cin >> D;

	vector<int> v(N);
	for(auto& ii : v) cin >> ii;

	sort(v.begin(), v.end());

	int best = N;
	int y = 0;
	for(int i=0;i<N;++i) {
		while(y < N && v[y]-v[i] <= D) {
			++ y;
		}
		best = min(best, N-(y-i));
	}
	if(v.back()-v[0] <= D) {
		best = 0;
	}
	cout << best << endl;

	return 0;
}