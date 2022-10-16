#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
int n,c[500005][2],ans[500005];
vector<int> e[500005],id[500005];
int book[500005];
void dfs(int now){
	for (int i=0;i<(int)e[now].size();i++){
		if (book[id[now][i]]==1)continue;
		book[id[now][i]]=1;
		if ((c[id[now][i]][0]-1)%n+1!=now)swap(c[id[now][i]][0],c[id[now][i]][1]);
		dfs(e[now][i]);
	}
	return;
}
int main(){
	cin>>n;
	if (n%2==0){
		puts("First");
		for (int i=1;i<=n;i++)printf("%d ",i);
		for (int i=1;i<=n;i++)printf("%d ",i);
		printf("\n");
		return 0;
	}
	puts("Second");
	fflush(stdout);
	for (int i=1;i<=2*n;i++){
		int x;
		scanf("%d",&x);
		if (c[x][0]==0)c[x][0]=i;
		else c[x][1]=i;
	}
	for (int i=1;i<=n;i++){
		int x=(c[i][0]-1)%n+1,y=(c[i][1]-1)%n+1;
		e[x].push_back(y),id[x].push_back(i);
		e[y].push_back(x),id[y].push_back(i);
	}
	for (int i=1;i<=n;i++)dfs(i);
	ll s=0;
	for (int i=1;i<=n;i++)s+=c[i][0];
	if (s%(2*n)!=0)
		for (int i=1;i<=n;i++)swap(c[i][0],c[i][1]); 
	for (int i=1;i<=n;i++)printf("%d ",c[i][0]);
	return 0;
}