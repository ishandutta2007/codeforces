#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 12;

vector<int> nxt[NMAX];
vector<int> a[NMAX];

int N, M;

pii fillFar(int u, vector<pii>& far, map<pii, int>& cnt, const int M) {
	if(far[u].first != -1) {
		return far[u];
	}
	if(cnt[pii(u,nxt[0][u])] == M) {
		pii res = fillFar(nxt[0][u], far, cnt, M);
		res.second++;
		far[u] = res;
		return res;
	}
	far[u] = pii(u, 1);
	return pii(u, 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	map<pii, int> cnt;
	for(int i=0;i<M;++i) {
		a[i] = vector<int>(N);
		nxt[i] = vector<int>(N+1, 0);
		for(int j=0;j<a[i].size();++j) {
			cin >> a[i][j];
			if(j != 0) {
				nxt[i][a[i][j-1]] = a[i][j];
				cnt[pii(a[i][j-1], a[i][j])]++;
			}
		}
	}
	vector<pii> far(N+1, pii(-1, -1));
	ll ans = 0;
	for(int i=1;i<=N;++i) {
		fillFar(i, far, cnt, M);
		ans += far[i].second;
	}
	cout << ans << endl;
	return 0;
}