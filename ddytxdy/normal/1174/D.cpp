#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,x,maxn,b[N],tot;bool vis[N];
int main(){
	scanf("%d%d",&n,&x);
	maxn=(1<<n)-1;
	for(int i=0;i<=maxn;i++){
		if(vis[i])continue;
		b[++tot]=i;vis[i^x]=1;
	}
	printf("%d\n",tot-1);
	for(int i=2;i<=tot;i++)printf("%d ",b[i]^b[i-1]);
	return 0;
}