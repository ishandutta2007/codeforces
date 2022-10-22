#include<bits/stdc++.h>
using namespace std;
int t,n,d,a[1000005];
int g[1000005];
int lev[1000005];
void sol(){
	queue<int>q;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)lev[i]=-1,g[i]=((i+d)%n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)lev[i]=0,q.push(i);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(lev[g[u]]<0)lev[g[u]]=lev[u]+1,q.push(g[u]);
	}
	for(int i=0;i<n;i++)if(lev[i]<0){
		puts("-1");
		return;
	}
	int ans=0;
	for(int i=0;i<n;i++)ans=max(ans,lev[i]);
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}