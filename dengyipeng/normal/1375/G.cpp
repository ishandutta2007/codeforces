#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int n,i,j,k,ans,sum;
int em,e[maxn*2],nx[maxn*2],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void dfs(int x,int p,int d){
	sum+=d&1^1;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs(e[i],x,d+1);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
	dfs(1,0,0);
	ans=min(sum,n-sum)-1;
	printf("%d\n",ans);
}