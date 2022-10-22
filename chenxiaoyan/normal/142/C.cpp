#include<bits/stdc++.h>
using namespace std;
#define dot(x,y) (a[x][y]=='.')
map<int,int> f[8][8];
int n,m,ans;
char a[15][15];
const int
	dx[][5]={{0,0,0,1,2},{0,1,1,1,2},{0,1,2,2,2},{0,1,1,1,2}},
	dy[][5]={{0,1,2,1,1},{2,0,1,2,2},{1,1,0,1,2},{0,0,1,2,0}};
int dp(int x,int y,int stt){
//	cout<<x<<" "<<y<<" "<<stt<<"\n";
	if(y==m-1)x++,y=1,stt>>=2;
	if(x==n-1)return 0;
	if(f[x][y].find(stt)!=f[x][y].end())return f[x][y][stt];
	int &res=f[x][y][stt]=dp(x,y+1,stt>>1),j;
	for(int i=0;i<4;i++){
		bool ok=true;
		for(j=0;j<5;j++)if(stt&(1<<dx[i][j]*m+dy[i][j])){ok=false;break;}
		if(!ok)continue;
		int nxt_stt=stt;
		for(j=0;j<5;j++)nxt_stt|=1<<dx[i][j]*m+dy[i][j];
		res=max(res,dp(x,y+1,nxt_stt>>1)+1);
	}
	return res;
}
void dfs(int x=1,int y=1,int now=0,int sp=n*m){
	int i,j;
	if(y==m-1)x++,y=1;
	if(x==n-1){
		if(now==ans){for(i=1;i<=n;i++)puts(a[i]+1);exit(0);}
		return;
	}
//	printf("%d %d %d %d:\n",x,y,now,sp);
//	for(i=1;i<=n;i++)puts(a[i]+1);
	if(now+sp/5<ans)return;//
	for(i=0;i<4;i++){
		bool ok=true;
		for(j=0;j<5;j++)if(a[x+dx[i][j]][y+dy[i][j]]!='.'){ok=false;break;}
		if(!ok)continue;
		for(j=0;j<5;j++)a[x+dx[i][j]][y+dy[i][j]]='A'+now;
		int nxtsp=sp-5-dot(x,y);
		if(x==n-2)nxtsp-=dot(n-1,y)+dot(n,y);
		else if(y==m-2)nxtsp-=dot(x,m-1)+dot(x,m);
		dfs(x,y+1,now+1,nxtsp);
		for(j=0;j<5;j++)a[x+dx[i][j]][y+dy[i][j]]='.';
	}
	sp-=dot(x,y);
	if(x==n-2)sp-=dot(n-1,y)+dot(n,y);
	else if(y==m-2)sp-=dot(x,m-1)+dot(x,m);
	dfs(x,y+1,now,sp);
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	if(n<3||m<3){puts("0");while(n--){for(i=1;i<=m;i++)putchar('.');puts("");}return 0;}
//	int cl=clock();
	for(i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]='.';
	ans=dp(1,1,0);
	printf("%d\n",ans);
//	cout<<clock()-cl;
	dfs();
}