#include<bits/stdc++.h>
using namespace std;
int f[1005][1005],ans,n,K;
void solve(int l,int r,int d){
	ans=max(ans,d);
	int N=r-l+1;
	if(N<=K){
		for(int i=l;i<=r;i++)for(int j=i+1;j<=r;j++)f[i][j]=d;
		return;
	}
	int s=N/K,w=N%K,p=K-w;
	int lst=l-1;
	while(w--){
		int L=lst+1,R=lst+s+1;
		for(int i=l;i<=lst;i++)for(int j=L;j<=R;j++)f[i][j]=d;
		solve(L,R,d+1);
		lst=R;
	}
	while(p--){
		int L=lst+1,R=lst+s;
		for(int i=l;i<=lst;i++)for(int j=L;j<=R;j++)f[i][j]=d;
		solve(L,R,d+1);
		lst=R;
	}
}
int main(){
	scanf("%d%d",&n,&K);
	solve(1,n,1);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)printf("%d ",f[i][j]);
}