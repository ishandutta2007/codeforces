#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int n,pri[N],tot,maxn,m;bool vis[N*2];
struct node{
	int x,y;
}ans[N*2];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=1200;i++){
		if(vis[i])continue;
		pri[++tot]=i;
		for(int j=i*i;j<=1200;j+=i)vis[j]=1;
	}
//	for(int i=1;i<=tot;i++)cout<<pri[i]<<" ",maxn=max(maxn,pri[i]-pri[i-1]);puts("");
//	cout<<maxn;
	for(int i=2;i<=n;i++)ans[++m]=(node){i-1,i};
	ans[++m]=(node){1,n};
	int j=1,k=1;
	while(pri[j]<m)j++;
	while(m<pri[j]){
		int y=k+n/2;y%=n;if(!y)y=n;
		ans[++m]=(node){k,y};
		k++;
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}