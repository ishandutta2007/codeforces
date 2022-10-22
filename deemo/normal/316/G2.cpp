#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 50;
const int LOG = 19;
const int INF = 1e9;

int m, p[MAXN], par[12][MAXN], nxt[MAXN], id[MAXN], ss[MAXN], ans, l[MAXN], r[MAXN];
int tt[LOG][MAXN], lc[LOG][MAXN];
string s[14];
pair<pair<int, int>, int>	vec[MAXN];

int lcp(int a, int b){
	int ta = a, tb = b;
	for (int i = LOG - 1; i >= 0 && a < nxt[ta] && b < nxt[tb]; i--)
		if (a + (1<<i) <= nxt[ta] && b + (1<<i) <= nxt[tb] && tt[i][a] == tt[i][b])
			a += 1 << i, b += 1 << i;
	return	a - ta;
}

bool ok(int sz, int ind){
	int tl = ind, tr = ind;
	for (int w = LOG - 1; w >= 0; w--)
		if (tr + (1<<w) < p[m] && lc[w][tr] >= sz)	tr += 1<<w;
	tr++;
	for (int w = LOG - 1; w >= 0; w--)
		if (tl - (1<<w) >= 0 && lc[w][tl - (1<<w)] >= sz)	tl -= (1<<w);
	
	for (int i = 1; i < m; i++)
		if (par[i][tr] - par[i][tl] > r[i])
			return	false;
	return	true;
}

bool ok2(int sz, int ind){
	int tl = ind, tr = ind;
	for (int w = LOG - 1; w >= 0; w--)
		if (tr + (1<<w) < p[m] && lc[w][tr] >= sz)	tr += 1<<w;
	tr++;
	for (int w = LOG - 1; w >= 0; w--)
		if (tl - (1<<w) >= 0 && lc[w][tl - (1<<w)] >= sz)	tl -= (1<<w);
	
	for (int i = 1; i < m; i++)
		if (par[i][tr] - par[i][tl] < l[i])	return	false;
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s[0] >> m;	m++;
	for (int i = 1; i < m; i++)
		cin >> s[i] >> l[i] >> r[i], p[i] = p[i - 1] + (int)s[i - 1].size();
	p[m] = p[m - 1] + (int)s[m - 1].size();

	for (int i = 0; i < m; i++)
		for (int j = 0; j < (int)s[i].size(); j++)
			tt[0][p[i] + j] = s[i][j];
	for (int w = 1; w < LOG; w++){
		for (int i = 0; i < m; i++)
			for (int j = 0; j < (int)s[i].size(); j++)
				if (j + (1 << (w - 1)) >= (int)s[i].size())
					vec[p[i] + j] = {{tt[w - 1][p[i] + j], -1}, p[i] + j};
				else
					vec[p[i] + j] = {{tt[w - 1][p[i] + j], tt[w - 1][p[i] + j + (1 << (w - 1))]}, p[i] + j};

		sort(vec, vec + p[m]);
		for (int i = 1; i < p[m]; i++)
			if (vec[i].first == vec[i - 1].first)
				tt[w][vec[i].second] = tt[w][vec[i - 1].second];
			else
				tt[w][vec[i].second] = i;
	}
	for (int i = 0; i < p[m]; i++)	ss[i] = vec[i].second;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < (int)s[i].size(); j++)
			id[p[i] + j] = i, nxt[p[i] + j] = p[i + 1];
	for (int i = 0; i < p[m]; i++)
		for (int j = 1; j < m; j++)
			par[j][i + 1] = par[j][i] + bool(id[ss[i]] == j);

	for (int i = 0; i < p[m] - 1; i++)
		lc[0][i] = lcp(ss[i], ss[i + 1]);
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < p[m] - 1; j++)
			if (j + (1 << (i-1)) >= p[m] - 1)
				lc[i][j] = lc[i - 1][j];
			else
				lc[i][j] = min(lc[i - 1][j], lc[i - 1][j + (1<<(i-1))]);

	int mn = 0;
	for (int i = 0; i < p[m]; i++){
		if (id[ss[i]]){
			mn = min(mn, lc[0][i]);
			continue;
		}
	
		int sz = nxt[ss[i]] - ss[i];
		int cur = ss[i];
		for (int w = LOG - 1; w >= 0 && cur < nxt[ss[i]]; w--)
			if (cur + (1<<w) <= nxt[ss[i]] && !ok(cur + (1<<w) - ss[i], i))
				cur += (1<<w);
	
		int cur2 = ss[i];
		for (int w = LOG - 1; w >= 0 && cur2 < nxt[ss[i]]; w--)
			if (cur2 + (1<<w) <= nxt[ss[i]] && ok2(cur2 + (1<<w) - ss[i], i))
				cur2 += (1<<w);
		

		cur = max(cur, ss[i] + mn);
		ans += max(0, cur2 - cur);
		mn = lc[0][i];
	}
	cout << ans << "\n";
	return	0;
}