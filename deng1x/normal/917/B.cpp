#include <bits/stdc++.h>

#define MAXN (110)

int n, m;
int sg[MAXN][MAXN][26];
std::vector<std::pair<int, char> > vec[MAXN];

int getsg(int x, int y, int w){
	if(~sg[x][y][w]) return sg[x][y][w];
	std::vector<int> v;
	for(auto &p : vec[x]){
		int to = p.first, ch = p.second;
		if(ch >= w){
			v.push_back(getsg(y, to, ch));
		}
	}
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	int &ret = sg[x][y][w];
	for(ret = 0; ret < (int)v.size() && v[ret] == ret; ++ ret);
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++ i){
		int u, v;
		char s[4];
		scanf("%d%d%s", &u, &v, s);
		vec[u].push_back({v, s[0] - 'a'});
	}
	memset(sg, -1, sizeof(sg));
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			printf("%c", getsg(i, j, 0) ? 'A' : 'B');
		}
		printf("\n");
	}
	return 0;
}