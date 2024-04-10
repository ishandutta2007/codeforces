#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

const int MAXN = 500 + 20;
const int MAXM = 1e4 + 20;

int n, m;
pair<int, int>	vec[MAXM];
vector<int>	sec[MAXM], gec[MAXM];
int comp[MAXN];

int get_comp(int v){
	if (v == comp[v])
		return	comp[v];
	return
		comp[v] = get_comp(comp[v]);
}

bool pute(int u, int v){
	if (get_comp(u) == get_comp(v))
		return	false;
	comp[get_comp(u)] = get_comp(v);
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	iota(comp, comp + n, 0);
	for (int i = 0; i < m; i++){
		cin >> vec[i].first >> vec[i].second;
		vec[i].first--, vec[i].second--;
		
		if (i)
			sec[i].assign(sec[i - 1].begin(), sec[i - 1].end());
		if (pute(vec[i].first, vec[i].second))
			sec[i].push_back(i);
	}

	iota(comp, comp + n, 0);
	for (int i = m - 1; i >= 0; i--){
		gec[i].assign(gec[i + 1].begin(), gec[i + 1].end());
		if (pute(vec[i].first, vec[i].second))
			gec[i].push_back(i);
	}

	int q;	cin >> q;
	while (q--){
		iota(comp, comp + n, 0);
		int l, r;	cin >> l >> r;	l--;
		int ret = n;
		if (l)
			for (int	e:sec[l - 1])
				if (pute(vec[e].first, vec[e].second))
					ret--;

		for (int e:gec[r])
			if (pute(vec[e].first, vec[e].second))
				ret--;
		cout << ret << "\n";
	}
	return 0;
}