#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5 + 5, MOD = 1e9 + 7;
int at[MN], ogd[MN], dd[MN];
vector<int> adj[MN];
int dist (int a, int b) {
	memset(dd,0x3f,sizeof dd);
	queue<int> q; dd[a]=0; q.push(a);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i : adj[cur]) if (dd[cur] + 1 < dd[i]) {
			dd[i] = dd[cur] + 1;
			q.push(i);
		}
	}
	return dd[b];
}
int main () {
	int n;
	scanf ("%d",&n);
	vector<pii> d(n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&ogd[i]);
		d[i-1] = {ogd[i],i};
	}
	sort(all(d)); reverse(all(d));
	vector<pii> edges; int ind = 0;
	for (pii &p : d) {
		++ind; 
		if (ind >= 1 + d[0].first) {
			if (p.first == 1) {
				edges.emplace_back(p.second * 2, p.second * 2 - 1);
				edges.emplace_back(p.second * 2,-1);
			} else {
				edges.emplace_back(-1,p.second * 2);
				edges.emplace_back(-(p.first-1),p.second * 2 - 1);
			}
		} else {
			at[ind] = p.second * 2 - 1;
			if (at[ind + p.first] || ind + p.first < 1 + d[0].first) edges.emplace_back(-(ind+p.first-1),p.second*2);
			else at[ind+p.first] = p.second * 2;
		}
	}
	for (int i = 1; at[i+1]; i++) {
		edges.emplace_back(at[i],at[i+1]);
	}
	for (pii &p : edges) {
		if (p.first < 0) p.first = at[-p.first];
		if (p.second < 0) p.second = at[-p.second];
		printf ("%d %d\n",p.first,p.second);
		assert(1 <= p.first && p.first <= 2*n);
		assert(1 <= p.second && p.second <= 2*n);
	}
	return 0;
}