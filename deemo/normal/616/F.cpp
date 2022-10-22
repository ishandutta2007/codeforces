//I found myself in Wonderland..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<cassert>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 100;
const int LOG = 21;

int n, val[MAXN], sz[MAXN], tt[LOG][MAXN], ss[MAXN], lc[MAXN], id[MAXN], comp[MAXN], cc[MAXN];
pair<int, int>	sec[MAXN];
ll sm[MAXN];
pair<pair<int, int>, int>	vec[MAXN];
string s[MAXN];

int lcp(int a, int b){
	int ta = a, xa = sz[id[a] + 1], xb = sz[id[b] + 1];
	for (int w = LOG - 1; w >= 0 && a < xa && b < xb; w--)
		if (a + (1<<w) <= xa && b + (1<<w) <= xb && tt[w][a] == tt[w][b])
			a += (1<<w), b += (1<<w);
	return	a - ta;
}

int get_comp(int v){
	if (comp[v] == v)
		return	v;
	return	comp[v] = get_comp(comp[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i], sz[i + 1] = sz[i] + (int)s[i].size();
	for (int i = 0; i < n; i++)	cin >> val[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)s[i].size(); j++)	
			tt[0][sz[i] + j] = s[i][j], id[sz[i] + j] = i;
	for (int w = 1; w < LOG; w++){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (int)s[i].size(); j++)
				if (j + (1<<(w - 1)) >= (int)s[i].size())
					vec[sz[i] + j] = {{tt[w - 1][sz[i] + j], -1}, sz[i] + j};
				else
					vec[sz[i] + j] = {{tt[w - 1][sz[i] + j], tt[w - 1][sz[i] + j + (1<<(w - 1))]}, sz[i] + j};

		sort(vec, vec + sz[n]);
		for (int i = 1; i < sz[n]; i++)
			if (vec[i].first == vec[i - 1].first)
				tt[w][vec[i].second] = tt[w][vec[i - 1].second];
			else
				tt[w][vec[i].second] = i;
	}
	iota(cc, cc + MAXN, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)s[i].size(); j++)	ss[cc[tt[LOG - 1][sz[i] + j]]++] = sz[i] + j;
	for (int i = 0; i < sz[n] - 1; i++){
		lc[i] = lcp(ss[i], ss[i + 1]);
		sec[i] = {lc[i], i};
	}

	ll ans = 0;
	for (int i = 0; i < sz[n]; i++){
		sm[i] = val[id[ss[i]]], comp[i] = i;
		if (cc[i] == i + 1)
			ans = max(ans, sm[i] * (ll)(sz[id[ss[i]] + 1] - ss[i]));
	}
	sort(sec, sec + sz[n] - 1);
	reverse(sec, sec + sz[n] - 1);
	for (int i = 0; i < sz[n] - 1;){
		int j = i;
		for (; i < sz[n] - 1 && sec[i].first == sec[j].first; i++){
			int v = sec[i].second;
			int a = get_comp(v), b = get_comp(v + 1);

			sm[b] += sm[a];
			comp[a] = b;
		}

		for (; j < i; j++){
			int v = sec[j].second, t = sec[j].first;
			int a = get_comp(v);
			ans = max(ans, ll(t) * ll(sm[a]));
		}
	}
	cout << ans << "\n";
	return	0;
}