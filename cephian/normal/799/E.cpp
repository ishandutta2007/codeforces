#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll INF = 0x7fffffffffffffffLL;
int n,m,k,c[N],a,b,q[N]={0};
vector<int> C[4];
vector<ll> pfx[4];

int pos(int i, int l, int s) {
	if(C[i].size() == 0 || C[i][s] > l) return 0;
	int lo = s,hi=C[i].size();
	while(lo+1 < hi) {
		int md = (lo+hi)/2;
		if(C[i][md] <= l) lo = md;
		else hi = md;
	}
	return hi-s;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	cin >> a;
	for(int i = 0; i < a; ++i) {
		int j;
		cin >> j;
		q[j-1] ^= 1;
	}
	cin >> b;
	for(int i = 0; i < b; ++i) {
		int j;
		cin >> j;
		q[j-1] ^= 2;
	}
	for(int i = 0; i < n; ++i) {
		C[q[i]].push_back(c[i]);
	}
	for(int i = 0; i < 4; ++i) {
		sort(C[i].begin(),C[i].end());
		pfx[i].push_back(0);
		for(int j = 0; j < C[i].size(); ++j)
			pfx[i].push_back(pfx[i].back() + C[i][j]);
	}
	ll mn = INF;
	
	for(int c3 = 0; c3 <= min(int(C[3].size()),m); ++c3) {
		int take = max(0, k-c3);
		if(take > C[1].size() || take > C[2].size()) continue;
		if(c3+2*take > m) continue;
		if(c3 + C[1].size()+C[2].size()+C[0].size() < m) continue;
		ll lo = -1,hi = 1e9;
		while(lo+1 < hi) {
			ll md = (lo+hi)/2;
			int amt = pos(0,md,0) + pos(1,md,take) + pos(2,md,take);
			if(amt+c3+2*take >= m) hi = md;
			else lo = md;
		}
		int amt = c3 + 2*take + pos(0,hi,0) + pos(1,hi,take) + pos(2,hi,take);
		ll sm = pfx[3][c3] + pfx[1][take + pos(1,hi,take)] + pfx[2][take + pos(2,hi,take)] + pfx[0][pos(0,hi,0)] - hi*(amt-m);
		mn = min(mn,sm);
	}
	if(mn == INF) cout << "-1\n";
	else cout << mn << "\n";
	return 0;
}