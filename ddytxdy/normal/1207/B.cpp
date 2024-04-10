#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,a[N][N],b[N][N],cx[N*N],cy[N*N],cnt,dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};
bool can(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&a[x][y];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]){
		bool flag=0;
		for(int k=0;k<4;k++){
			bool flagg=1;int mnx=i,mny=j;
			for(int ii=0;ii<2;ii++){
				for(int jj=0;jj<2;jj++){
					int xx=i+ii*dx[k],yy=j+jj*dy[k];
					mnx=min(mnx,xx);mny=min(mny,yy);
					if(!can(xx,yy))flagg=0;
				}
			}
			if(flagg){cx[++cnt]=mnx,cy[cnt]=mny;flag=1;break;}
		}
		if(!flag)puts("-1"),exit(0);
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",cx[i],cy[i]);
	return 0;
}