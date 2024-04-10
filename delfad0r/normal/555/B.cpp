#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<ll, ll> llll;

int N, M;
llll I[200005];
llll R[200005];
ll B[200005];
int sR[200005], sB[200005];
int ans[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for(int n = 0; n < N; ++n) cin >> I[n].first >> I[n].second;
	for(int m = 0; m < M; ++m) cin >> B[m];
	
	for(int n = 0; n < N - 1; ++n) {
		R[n].first = I[n + 1].first - I[n].second;
		R[n].second = I[n + 1].second - I[n].first;
	}
	
	iota(sR, sR + N - 1, 0);
	iota(sB, sB + M, 0);
	sort(sR, sR + N - 1, [&](const int & x, const int & y) {
		return R[x].first < R[y].first;
	});
	sort(sB, sB + M, [&](const int & x, const int & y) {
		return B[x] < B[y];
	});
	/*for(int n = 0; n < N - 1; ++n) cout << sR[n] << ' ';
	cout << '\n';
	for(int m = 0; m < M; ++m) cout << sB[m] << ' ';
	cout << '\n';*/
	
	priority_queue<lli, vector<lli>, greater<lli>> Q;
	int filled = 0;
	for(int m = 0, n = 0; m < M && filled < N - 1; ++m) {
		while(n < N - 1 && R[sR[n]].first <= B[sB[m]]) {
			Q.emplace(R[sR[n]].second, sR[n]);
			++n;
		}
		if(Q.size() && Q.top().first < B[sB[m]]) {
			cout << "No\n";
			return 0;
		}
		if(Q.size()) {
			//cout << Q.top().second << " -> " << sB[m] << '\n';
			ans[Q.top().second] = sB[m];
			Q.pop();
			++filled;
		}
	}
	if(filled < N - 1) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for(int n = 0; n < N - 1; ++n) cout << ans[n] + 1 << ' ';
}