/*
   mezameta kokoro ha hashiridashita mirai wo egaku tame
   muzukashii michi de tachidomattemo
   sora ha kireina aosa de itsumo mattetekureru
   dakara kowakunai
   mou nani ga attemo kujikenai..
*/

#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;
const int MAXK = 1e6 + 10;

int n, k, par[MAXN], val[MAXN], sz[MAXN];
ll p[MAXN];
vector<int>	vec[MAXK];
pair<int, int>	sec[MAXN];

int get_comp(int v){
	if (par[v] == v)	return	v;
	return	par[v] = get_comp(par[v]);
}

int cnt(int l, int r, int x){return max(0, (int)(lower_bound(vec[x].begin(), vec[x].end(), r) - lower_bound(vec[x].begin(), vec[x].end(), l)));}

int main(){
	scanf("%d %d", &n, &k);
	vec[0].push_back(0);
	for (int i = 1; i <= n; i++){
		scanf("%d", &val[i]);
		p[i] = p[i - 1] + val[i];
		vec[p[i] % k].push_back(i);
		sec[i - 1] = {val[i], i};
	}
	sort(sec, sec + n);
	iota(par, par + MAXN, 0);
	
	ll ans = 0;
	for (int i = 0; i < n; i++){
		auto v = sec[i];
		sz[v.second] = 1;
		
		int aa = get_comp(v.second - 1), bb = get_comp(v.second + 1);
		if (sz[aa])
			ans += cnt(v.second - sz[aa] - 1, v.second - 1, p[v.second - 1] % k);
		if (sz[bb])
			ans += cnt(v.second + 1, v.second + sz[bb] + 1, p[v.second] % k);
		if (sz[aa] && sz[bb]){
			if (sz[aa] <= sz[bb])
				for (int j = v.second - sz[aa]; j < v.second; j++)
					ans += cnt(v.second + 1, v.second + sz[bb] + 1, (p[j - 1] + v.first) % k);
			else
				for (int j = v.second + 1; j <= v.second + sz[bb]; j++)
					ans += cnt(v.second - sz[aa] - 1, v.second - 1, (p[j] + k - (v.first % k)) % k);

		}

		//
		if (sz[aa])
			par[aa] = v.second, sz[v.second] += sz[aa];
		if (sz[bb])
			par[bb] = v.second, sz[v.second] += sz[bb];
	}
	
	printf("%I64d\n", ans);
	return	0;
}