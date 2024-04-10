#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<set>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, cn[MAXN];
set<int>	st;
vector<pair<int, int>>	adj[MAXN];

bool ok(int mid){
	memset(cn, 0, sizeof(cn));
	st.clear();
	for (int v = 0; v < n; v++)
		for (auto u:adj[v])
			if (u.second < mid)
				cn[u.first]++;
			else 
				break;

	for (int i = 0; i < n; i++)
		if (cn[i] == 0)	st.insert(i);

	while (st.size()){
		if (st.size() > 1)	return	false;
		int v = *st.begin();
		st.erase(st.begin());
		for (auto u:adj[v])
			if (u.second < mid){
				cn[u.first]--;
				if (cn[u.first] == 0)	st.insert(u.first);
			}
			else
				break;
	}
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back({b, i});
	}
	int b = 1, e = m, ret = m + 1;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (ok(mid))
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	if (ret > m)
		cout << "-1\n";
	else
		cout << ret << "\n";
	return	0;
}