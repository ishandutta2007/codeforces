#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int n,m,ans;
vector<int> e[200005];
int dfs(int x,int fa){
	int f=0;
	for(int y:e[x])if(y!=fa){
		f|=!dfs(y,x);
	}
	if(f){
		if(x!=1) ans--;
	}
	else{
		ans++;
	}
	return f;
}
void solve(){
	int i;
	ans=0;
	scanf("%d",&n);
	rep(i,n) e[i].clear();
	rep(i,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}