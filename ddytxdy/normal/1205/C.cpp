#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n,b[N*2],ans[N][N],tot,dx[6]={0,1,2,0,-1,-2},dy[6]={2,1,0,-2,-1,0},p;bool flag[N][N];
struct node{int x,y;}a[N*2],c[N*N];
bool ask(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	cout.flush();int ret;
	scanf("%d",&ret);
	return ret^1;
}
bool can(int x,int y){return x>=1&&x<=n&&y>=1&&y<=n&&!flag[x][y];}
int main(){
	scanf("%d",&n);
	ans[1][1]=1;ans[n][n]=0;
	c[++tot]=(node){1,1};flag[1][1]=1;
	c[++tot]=(node){n,n};flag[n][n]=1;
	for(int i=1;i<=n;i++)a[i]=(node){i,1};
	for(int i=1;i<n;i++)a[i+n]=(node){n,i+1};
	for(int i=1;i<=2*n-3;i++)b[i]=ask(a[i].x,a[i].y,a[i+2].x,a[i+2].y);
	for(int i=1;i<=2*n-3;i++){
		int x1=a[i].x,y1=a[i].y,x2=a[i+2].x,y2=a[i+2].y;
		if((x1+y1)&1)continue;
		ans[x2][y2]=ans[x1][y1]^b[i];
		c[++tot]=(node){x2,y2};flag[x2][y2]=1;
	}
	for(int i=1;i<2*n-3;i++)if(b[i]==b[i+1]){
		int x1=a[i].x,y1=a[i].y,x2=a[i+3].x,y2=a[i+3].y,dat=ask(x1,y1,x2,y2);
		if((x1+y1)&1)ans[x1][y1]=ans[x2][y2]^dat,c[++tot]=(node){x1,y1},flag[x1][y1]=1,p=i;
		else ans[x2][y2]=ans[x1][y1]^dat,c[++tot]=(node){x2,y2},flag[x2][y2]=1,p=i+3;
		break;
	}
	for(int i=p;i>2;i-=2){
		int x=a[i-2].x,y=a[i-2].y;
		ans[x][y]=ans[a[i].x][a[i].y]^b[i-2];
		c[++tot]=(node){x,y};flag[x][y]=1;
	}
	for(int i=p;i<=2*n-3;i++){
		int x=a[i+2].x,y=a[i+2].y;
		ans[x][y]=ans[a[i].x][a[i].y]^b[i];
		c[++tot]=(node){x,y};flag[x][y]=1;
	}
	for(int i=1;i<=tot;i++){
		int x=c[i].x,y=c[i].y;
		for(int j=0;j<6;j++){
			int xx=x+dx[j],yy=y+dy[j];
			if(can(xx,yy)){
				int x1=x,y1=y,x2=xx,y2=yy;
				if(x1>x2)swap(x1,x2),swap(y1,y2);
				ans[xx][yy]=ans[x][y]^ask(x1,y1,x2,y2);
				c[++tot]=(node){xx,yy};flag[xx][yy]=1;
			}
		}
	}
	puts("!");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d",ans[i][j]);
		puts("");
	}
	return 0;
}