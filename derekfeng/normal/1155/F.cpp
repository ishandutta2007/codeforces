#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int dp[16400];
int n,m,cnt;
int cap[16],miko[16400];
bool link[16400][15][15];
int lfr[16400][15][15];
int fr1[16400],fr2[16400],fr3[16400];
bool vis[15][15]; 
void dfslink(int msk,int st,int ed){
	if(st==ed)return;
	dfslink(msk^(1<<ed),st,lfr[msk][st][ed]);
	printf("%d %d\n",ed+1,lfr[msk][st][ed]+1);
	vis[ed][lfr[msk][st][ed]]=1;
	vis[lfr[msk][st][ed]][ed]=1;
}
void dfs(int msk){
	int fr=fr1[msk];
	if(fr>0){
		dfs(fr);
		dfslink(fr^msk,fr2[msk],fr3[msk]);
		bool yes1=1,yes2=1;
		int a=fr2[msk],b=fr3[msk];
		for(int i=0;i<n;i++)if((1<<i)&fr){
			if(yes1&&((1<<i)&cap[a])>0&&vis[a][i]==0)yes1=0,printf("%d %d\n",a+1,i+1),vis[a][i]=1,vis[i][a]=1;
			if(yes2&&((1<<i)&cap[b])>0&&vis[b][i]==0)yes2=0,printf("%d %d\n",b+1,i+1),vis[b][i]=1,vis[i][b]=1;
		}
	}else{
		dfslink(msk,fr2[msk],fr3[msk]);
		printf("%d %d\n",fr2[msk]+1,fr3[msk]+1);
		vis[fr2[msk]][fr3[msk]]=1;
		vis[fr3[msk]][fr2[msk]]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v),u--,v--;
		cap[u]|=(1<<v),cap[v]|=(1<<u);
	}
	for(int i=0;i<(1<<n);i++)miko[i]=__builtin_popcount(i);
	for(int i=0;i<n;i++)link[1<<i][i][i]=1;
	for(int i=1;i<(1<<n);i++) 
		for(int j=0;j<n;j++)if((1<<j)&i)
			for(int k=0;k<n;k++)if(link[i][j][k])
				for(int l=0;l<n;l++)if(((1<<l)&i)<1&&(cap[l]&(1<<k))>0)
					link[i|(1<<l)][j][l]=1,lfr[i|(1<<l)][j][l]=k;
	for(int i=0;i<(1<<n);i++)dp[i]=300;
	for(int i=1;i<(1<<n);i++)if(miko[i]>2)
		for(int j=0;j<n;j++)if((1<<j)&i)
			for(int k=0;k<n;k++)if(link[i][j][k]&&(cap[j]&(1<<k))>0)
				if(miko[i]<dp[i])dp[i]=miko[i],fr1[i]=0,fr2[i]=j,fr3[i]=k;
	for(int i=1;i<(1<<n);i++)if(dp[i]<300)
		for(int j=0;j<n;j++)if((i&(1<<j))<1&&(cap[j]&i)>0)
			for(int k=0;k<n;k++)if((i&(1<<k))<1&&(cap[k]&i)>0){
				if(j==k&&miko[(cap[j]&i)]==1)continue; 
				int now=(((1<<n)-1)^i);
				for(int msk=now;msk;msk=(msk-1)&now)if(link[msk][j][k])
					if(dp[i|msk]>miko[msk]+1+dp[i])dp[i|msk]=miko[msk]+1+dp[i],fr1[i|msk]=i,fr2[i|msk]=j,fr3[i|msk]=k;
			}
	cout<<dp[(1<<n)-1]<<"\n";
	dfs((1<<n)-1);
}