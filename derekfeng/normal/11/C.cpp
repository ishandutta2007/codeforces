#include<bits/stdc++.h>
using namespace std;
int d[8][2]={{0,1},{-1,0},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int T;
int n,m,tot;
char c[253][253];
int check1(int sx,int sy){
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	while(sx<n&&c[sx+1][sy])sx++,cnt1++;
	while(sy<m&&c[sx][sy+1])sy++,cnt2++;
	while(sx>1&&c[sx-1][sy])sx--,cnt3++;
	while(sy>1&&c[sx][sy-1])sy--,cnt4++;
	return (cnt1==cnt2&&cnt2==cnt3&&cnt3==cnt4)?cnt1:0;
}
int check2(int sx,int sy){
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	while(sx<n&&sy>1&&c[sx+1][sy-1])sx++,sy--,cnt1++;
	while(sx<n&&sy<m&&c[sx+1][sy+1])sx++,sy++,cnt2++;
	while(sx>1&&sy<m&&c[sx-1][sy+1])sx--,sy++,cnt3++;
	while(sx>1&&sy>1&&c[sx-1][sy-1])sx--,sy--,cnt4++;
	return (cnt1==cnt2&&cnt2==cnt3&&cnt3==cnt4)?cnt1:0;	
}
void bfs(int sx,int sy){
	queue<int>q1,q2;
	q1.push(sx),q2.push(sy),c[sx][sy]=0;
	while(!q1.empty()){
		tot++;
		int u=q1.front(),v=q2.front();q1.pop(),q2.pop();
		for(int i=0;i<8;i++){
			int uu=u+d[i][0],vv=v+d[i][1];
			if(uu>0&&vv>0&&uu<=n&&vv<=m&&c[uu][vv])q1.push(uu),q2.push(vv),c[uu][vv]=0;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",c[i]+1);
			for(int j=1;j<=m;j++)c[i][j]-='0';
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[i][j]){
			int x=check1(i,j),y=check2(i,j);
			tot=0,bfs(i,j);
			if(x*4==tot||y*4==tot)ans++;
		}
		printf("%d\n",ans);
	}
}