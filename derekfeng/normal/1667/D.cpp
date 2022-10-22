#include<bits/stdc++.h>
using namespace std;
int n,fa[200004];
vector<int>tr[200004];
int pr[200004];
bool dfs(int x){
	int cnt[2]={0,0};
	for(auto y:tr[x])if(y!=fa[x]){
		fa[y]=x;
		if(dfs(y))return 1;
		cnt[pr[y]]++;
	}
	if(x!=1)pr[x]=cnt[0]>=cnt[1],cnt[pr[x]]++;
	if(cnt[1]<cnt[0]||cnt[1]>cnt[0]+1)return 1;
	return 0;
}
void getans(int x){
	vector<int>ver[2];
	for(auto y:tr[x]){
		if(fa[x]==y)ver[pr[x]].push_back(x);
		else ver[pr[y]].push_back(y);
	}
	int cur=((int)tr[x].size())&1;
	for(int i=0;i<tr[x].size();i++){
		int y=ver[cur].back();ver[cur].pop_back();
		if(y==x)printf("%d %d\n",x,fa[x]);
		else getans(y);
		cur^=1;
	}
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)tr[i].clear();
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back(v),tr[v].push_back(u);
	}
	if(dfs(1)){puts("NO");return;}
	puts("YES"),getans(1);
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}