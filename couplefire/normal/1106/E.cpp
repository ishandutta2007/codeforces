#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5+3;
typedef long long ll;
struct Env {
	int s, t, d;
	ll w;
};
Env arr[MX];
int got[MX];
ll dp[201][MX];
struct comp {
	bool operator()(int i, int j) {
		Env& a = arr[i], b = arr[j];
		return a.w == b.w ? a.d < b.d : a.w < b.w;
	}
};
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=k; i++) {
		cin >> arr[i].s >> arr[i].t >> arr[i].d >> arr[i].w;
	}
	sort(arr+1, arr+k+1, [](Env &a, Env &b){
		return a.s < b.s;
	});
	priority_queue<int, vector<int>, comp> pq;
	int i = 1;
	for(int t=1; t<=n; t++) {
		while(i <= k && arr[i].s <= t)
			pq.push(i++);
		while(!pq.empty() && arr[pq.top()].t < t)
			pq.pop();
		if(!pq.empty())
			got[t] = pq.top();
	}
	for(int p=0; p<=m; p++) {
		for(int t=n; t; t--) {
			if(got[t]) {
				dp[p][t] = arr[got[t]].w + dp[p][arr[got[t]].d+1];
			} else {
				dp[p][t] = dp[p][t+1];
			}
			if(p) {
				dp[p][t] = min(dp[p][t], dp[p-1][t+1]);
			}
		}
	}
	cout << dp[m][1];
}