#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define FAIL {cout << "-1\n"; exit(0);}

const int MAXN = 2e5 + 10;

ll n, from[MAXN], to[MAXN], w[MAXN], s[MAXN], cw[MAXN], cs[MAXN], csm[MAXN];
vector<int>	adj[MAXN];
set<pair<ll, int>>	st;
ll x;
bool del[MAXN];

ll dfs(int v, int p = -1){
	ll sm = 0;
	for (int e:adj[v])
		sm += dfs(to[e], e);

	if (~p){
		csm[p] = sm;
		ll g = max(0ll, sm-cs[p]);
		cs[p] += g;
		cw[p] += g;
		if (cs[p] > s[p])
			FAIL
		sm += cw[p];
	}
	return sm;
}

void dfs2(int v, int p = -1){
	if (~p){
		while (st.size() && del[st.begin()->S])
			st.erase(st.begin());

		ll g = s[p] - cs[p];
		if (st.size()){
			auto it = *st.begin();
			g = min(g, it.F+x);
		}
	//	cout << g << " " << x << " " << csm[p] << endl;
		cs[p] += g, cw[p] += g;
		x -= g;
		st.insert({s[p] - csm[p] - x, p});
	}
		
	for (int e:adj[v])
		dfs2(to[e], e);
	del[p] = 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int e = 0; e < n - 1; e++){
		cin >> from[e] >> to[e] >> w[e] >> s[e], from[e]--, to[e]--;
		adj[from[e]].push_back(e);

		cw[e] = w[e], cs[e] = s[e];
		ll g = min(w[e]-1, s[e]);
		cw[e] -= g;
		cs[e] -= g;
	}

	dfs(0);
	dfs2(0);

	cout << n << "\n";
	for (int e = 0; e < n-1; e++)
		cout << from[e]+1 << " " << to[e]+1 << " " << cw[e] << " " << cs[e] << "\n";
	return 0;
}