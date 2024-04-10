//I'm freaking out, so where am I now?
//Upside down, and I can't stop it now..

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<cassert>

using namespace std;

const int MAXN = 200 + 5;
const int MAXS = 3e6 + 10;

int n, m, q, c[MAXN][MAXN], xx[20], yy[20], col[MAXS], g, hs[MAXN][MAXN], ss[MAXS], ord[MAXS];
bool in_cycle[MAXS];
int vis[MAXS];
vector<int>	st;
string s;
int lst[MAXS], nd[MAXS];

bool fit(int a, int b){return	0 <= a && a < n && 0 <= b && b < m;}

void dfs(int v){
	vis[v] = 1;
	int a = v/m, b = v % m;
	int z = c[a][b];
	int ta = a + xx[z], tb = b + yy[z];
	if (!fit(ta, tb))	ta = a, tb = b;
	if (vis[hs[ta][tb]] == 0)	dfs(hs[ta][tb]);
	else if (vis[hs[ta][tb]] == 1)	in_cycle[v] = 1;
	vis[v] = 2;
	st.push_back(v);
}

void dfs2(int v){
	col[v] = g;
	int a = v/m, b = v % m;
	int z = c[a][b];
	int ta = a + xx[z], tb = b + yy[z];
	ss[g] |= 1<<z;
	if (fit(ta, tb) && col[hs[ta][tb]] == 0)
		dfs2(hs[ta][tb]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			char ch;	cin >> ch;
			c[i][j] = ch - '0';
			hs[i][j] = i * m + j;
		}
	for (int i = 0; i < 10; i++)
		cin >> xx[i] >> yy[i];
		
	for (int i = 0; i < n * m; i++)
		if (vis[i] == 0)	dfs(i);
	for (int i = 0; i < n * m; i++)
		if (in_cycle[i])	g++, dfs2(i);

	reverse(st.begin(), st.end());
	for (int i = 0; i < (int)st.size(); i++)	ord[st[i]] = i;
	for (int i = 0; i < n * m; i++){
		int a = i/m, b = i % m;
		int z = c[a][b];
		int ta = a + xx[z], tb = b + yy[z];
		if (!fit(ta, tb))	continue;
		assert((col[i] && col[hs[ta][tb]] == col[i]) || ord[i] < ord[hs[ta][tb]]);
	}

	while (q--){
		cin >> s;
		memset(nd, 0, sizeof(nd));
		for (int i = (int)s.size() - 1; i >= 0; i--)	nd[i] = nd[i + 1] | (1<<int(s[i] - '0'));
		memset(lst, 0, sizeof(lst));
		
		bool fl = 0;
		for (int u:st){
			if (col[u] == 0){
				int a = u/m, b = u % m;
				int z = c[a][b];
				int ta = a + xx[z], tb = b + yy[z];
				lst[hs[ta][tb]] = max(lst[hs[ta][tb]], lst[u] + bool(lst[u] < (int)s.size() && c[a][b] == s[lst[u]] - '0'));
			}
			else if ((ss[col[u]] | nd[lst[u]]) == ss[col[u]])	fl = 1;
			if (fl)	break;
		}
		if (fl)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return	0;
}