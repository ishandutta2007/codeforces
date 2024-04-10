#include <bits/stdc++.h>

#define MAXN (100010)

int n, m;
//f[i] = 1 must cap
//f[i] = 2 cannot cap
int f[MAXN], ans;
std::vector<int> word[MAXN], vec[MAXN];

void dfs(int u){
	for(auto v : vec[u]){
		if(f[v] == 2) ans = 1;
		else if(!f[v]){
			f[v] = 1;
			dfs(v);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i){
		int x, y;
		scanf("%d", &x);
		for(int j = 1; j <= x; ++ j){
			scanf("%d", &y);
			word[i].push_back(y);
		}
	}
	
	for(int i = 1; i < n; ++ i){
		int j;
		for(j = 0; j < (int)word[i].size() && j < (int)word[i + 1].size(); ++ j){
			if(word[i][j] != word[i + 1][j]){
				break;
			}
		}
		if(j == (int)word[i].size() || j == (int)word[i + 1].size()){
			if(word[i].size() > word[i + 1].size()){
				ans = 1;
			}
		}
		else{
			if(word[i][j] < word[i + 1][j]){
				vec[word[i + 1][j]].push_back(word[i][j]);
			}
			else{
				if(f[word[i][j]] == 2 || f[word[i + 1][j]] == 1){
					ans = 1;
				}
				else{
					f[word[i][j]] = 1;
					f[word[i + 1][j]] = 2;
				}
			}
		}
	}
	
	for(int i = 1; i <= m; ++ i){
		if(f[i] == 1){
			dfs(i);
		}
	}
	
	if(ans){
		printf("No\n");
	}
	else{
		printf("Yes\n");
		int ret = 0;
		for(int i = 1; i <= m; ++ i) ret += (f[i] == 1);
		printf("%d\n", ret);
		for(int i = 1; i <= m; ++ i){
			if(f[i] == 1){
				printf("%d ", i);
			}
		}
		puts("");
	}
	return 0;
}