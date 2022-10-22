#include<bits/stdc++.h>
using namespace std;
int nxt[503][10],cnt,flg[503];
int n,a,K,d[503];
char c[503];
void add(){
	int m=strlen(c),cur=0;
	for(int i=0;i<m;i++){
		int x=c[i]-'0';
		if(!nxt[cur][x])nxt[cur][x]=++cnt,d[cnt]=d[cur]+1;
		cur=nxt[cur][x];
	}
	flg[cur]+=a;
}
int f[503][503][13],g[503][503][13],t[503][503][13];
void dp(int x,int lst){
	if(~f[x][lst][0])return;
	for(int i=0;i<=K;i++)f[x][lst][i]=1e9;
	for(int i=0;i<10;i++)if(nxt[x][i]){
		dp(nxt[x][i],lst);
		if(K>0)dp(nxt[x][i],d[x]);
	}
	for(int i=1;i<=K;i++)g[x][lst][i]=1e9;
	g[x][lst][0]=0;
	for(int i=0;i<10;i++)if(nxt[x][i]){
		int y=nxt[x][i];
		for(int j=0;j<=K;j++)t[x][lst][j]=1e9;
		for(int j=0;j<=K;j++)for(int l=0;l+j<=K;l++)
			t[x][lst][j+l]=min(t[x][lst][j+l],g[x][lst][j]+f[y][lst][l]);
		for(int j=0;j<=K;j++)g[x][lst][j]=t[x][lst][j];
	}
	for(int i=0;i<=K;i++){
		f[x][lst][i]=g[x][lst][i]+flg[x]*(d[x]-lst);
		if(i>0)f[x][lst][i]=min(f[x][lst][i-1],f[x][lst][i]);
	}
	if(K>0){
		for(int i=1;i<=K;i++)g[x][lst][i]=1e9;
		g[x][lst][0]=0;
		for(int i=0;i<10;i++)if(nxt[x][i]){
			int y=nxt[x][i];
			for(int j=0;j<=K;j++)t[x][lst][j]=1e9;
			for(int j=0;j<=K;j++)for(int l=0;l+j<=K;l++)
				t[x][lst][j+l]=min(t[x][lst][j+l],g[x][lst][j]+f[y][d[x]][l]);
			for(int j=0;j<=K;j++)g[x][lst][j]=t[x][lst][j];
		}
		for(int i=1;i<=K;i++){
			f[x][lst][i]=min(f[x][lst][i],g[x][lst][i-1]);
			if(i>0)f[x][lst][i]=min(f[x][lst][i-1],f[x][lst][i]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%s%d",c,&a);
		add();
	}
	memset(f,-1,sizeof(f));
	dp(0,0);
	printf("%d\n",f[0][0][K]);
}