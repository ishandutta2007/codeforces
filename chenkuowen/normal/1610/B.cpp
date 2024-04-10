#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
int s[N];
bool dfs(int x,int y,int z){
	if(x>=y) return true;
	if(s[x]==s[y]) return dfs(x+1,y-1,z);
	if(z==-1){
		return dfs(x+1,y,s[x])||dfs(x,y-1,s[y]);
	}
	if(s[x]==z) return dfs(x+1,y,z);
	if(s[y]==z) return dfs(x,y-1,z);
	return false;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&s[i]);
		if(dfs(1,n,-1)) puts("YES");
		else puts("NO");
	}
	return 0;
}