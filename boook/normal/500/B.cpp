#include<bits/stdc++.h>
using namespace std;
int a[310] , vis[310];
vector<int> G[320] , val , sol;
char s[310][310];

void dfs(int u){
	vis[u] = 1;
	sol.push_back(u);
	val.push_back(a[u]);
	
	for(int i = 0; i < G[u].size(); i++){
		if(!vis[G[u][i]]){
			dfs(G[u][i]);
		}
	} 
}
int main(){
	int n;
	scanf("%d" , &n);
	for(int i = 0 ; i < n; i++){
		scanf("%d" , &a[i]);
	}
	
	for(int i = 0; i < n; i++){
		scanf("%s" , s[i]); 
	} 
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(s[i][j] == '1'){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	
	for(int i = 0; i < n; i++) if(!vis[i]){
		dfs(i);
		sort(val.begin() , val.end());
		sort(sol.begin() , sol.end());
		for(int j = 0; j < sol.size(); j++){
			a[sol[j]] = val[j];
		}
		sol.clear();
		val.clear();
	}
	for(int i = 0; i < n; i++){
		printf("%d " , a[i]);
	}
	puts("");
	return 0;
}