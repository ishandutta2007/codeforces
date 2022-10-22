#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 5e5 + 10;

int n, q, s_t[MAXN], f_t[MAXN], tm;
char c[MAXN];
bool ans[MAXN];
vector<int>	adj[MAXN];
vector<pair<int, char>>	s[MAXN];
vector<pair<pair<int, int>, int>>	vec[MAXN];
int sec[MAXN][27];

void plant(int v, int de = 1){
	s_t[v] = tm++;
	s[de].push_back({s_t[v], c[v]});
	for (int u:adj[v])
		plant(u, de + 1);
	f_t[v] = tm;
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i < n; i++){
		int a;	scanf("%d", &a);	a--;
		adj[a].push_back(i);
	}	
	for (int i = 0; i < n; i++)	scanf("%1s", &c[i]);
	plant(0);
	for (int i = 0; i < q; i++){
		int v, h;	scanf("%d %d", &v, &h);	v--;
		int l = lower_bound(s[h].begin(), s[h].end(), make_pair(s_t[v], char(1))) - s[h].begin();
		int r = lower_bound(s[h].begin(), s[h].end(), make_pair(f_t[v], char(1))) - s[h].begin();
		vec[h].push_back({{l, r}, i});
	}

	for (int i = 1; i <= n; i++){
		int sz = s[i].size();
		for (int j = 0; j < sz; j++)
			for (int w = 0; w < 26; w++)
				sec[j + 1][w] = sec[j][w] + bool(s[i][j].second - 'a' == w);
		for (auto v:vec[i]){
			int cn = 0;
			for (int w = 0; w < 26; w++)
				if ((sec[v.first.second][w] - sec[v.first.first][w]) % 2 == 1)	cn++;
			ans[v.second] = bool(cn < 2);
		}
	}

	for (int i = 0; i < q; i++)
		if (ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	return	0;
}