#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>

using namespace std;

const int MAXN = 2e4 + 10;
const int LOG = 15;

int n, sz[MAXN], id[MAXN], lc[MAXN], tt[LOG + 2][MAXN], ss[MAXN], cc[MAXN];
string s[2];
pair<pair<int, int>, int>	vec[MAXN];

int lcp(int a, int b){
	int ta = a, xa = sz[id[a] + 1], xb = sz[id[b] + 1];
	for (int w = LOG - 1; w >= 0 && a < xa && b < xb; w--)
		if (a + (1<<w) <= xa && b + (1<<w) <= xb && tt[w][a] == tt[w][b])
			a += (1<<w), b += (1<<w);	
	return	a - ta;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = 2;
	for (int i = 0; i < n; i++)
		cin >> s[i], sz[i + 1] = sz[i] + (int)s[i].size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int)s[i].size(); j++)
			tt[0][sz[i] + j] = s[i][j], id[sz[i] + j] = i;
	for (int w = 1; w < LOG; w++){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (int)s[i].size(); j++)	
				if (j + (1 << (w - 1)) >= (int)s[i].size())
					vec[sz[i] + j] = {{tt[w - 1][sz[i] + j], -1}, sz[i] + j};
				else
					vec[sz[i] + j] = {{tt[w - 1][sz[i] + j], tt[w - 1][sz[i] + j + (1<< (w - 1))]}, sz[i] + j};

		sort(vec, vec + sz[n]);
		for (int i = 1; i < sz[n]; i++)
			if (vec[i].first == vec[i - 1].first)
				tt[w][vec[i].second] = tt[w][vec[i - 1].second];
			else
				tt[w][vec[i].second] = i;
	}
	iota(cc, cc + MAXN, 0);
	for (int i = 0; i < sz[n]; i++)	ss[cc[tt[LOG - 1][i]]++] = i;
	for (int i = 0; i < sz[n] - 1; i++)
		lc[i] = lcp(ss[i], ss[i + 1]);
	int ans = sz[n] + 5;
	for (int i = 0; i < sz[n] - 1; i++){
		if (id[ss[i]] == id[ss[i + 1]])	continue;
		int r = lc[i];
		int l = 0;
		if (i)	l = max(l, lc[i - 1]);
		if (i < sz[n] - 2)	
			l = max(l, lc[i + 1]);
		if (l < r)
			ans = min(ans, l + 1);
	}

	if (ans == sz[n] + 5)	ans = -1;
	cout << ans << "\n";
	return	0;
}