#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 520
#define maxd 20000005
using namespace std;

const int fx[2][3][2]={{{1,0},{-1,0},{1,-1}},{{1,0},{-1,0},{-1,1}}};
int n,i,j,k,cnt[maxn][maxn],d[maxd][2],bz[maxn][maxn],ans,a[maxn][maxn],vis[maxn][maxn];

void dfs(int x,int y,int px,int py){
	vis[x][y]=1;
	for(int k=0;k<3;k++){
		int xx=x+fx[x&1][k][0],yy=y+fx[x&1][k][1];
		if (xx>=0&&yy>=0&&(xx!=px||yy!=py)) if (bz[xx][yy]){
			if (vis[xx][yy]){
				printf("SICK\n");
				exit(0);
			}
			dfs(xx,yy,x,y);
		}
	}
}

int check(int x,int y){
	for(int k=0;k<3;k++){
		int xx=x+fx[x&1][k][0],yy=y+fx[x&1][k][1];
		if (xx<0||yy<0) return 0;
		if (!bz[xx][yy]||!a[xx][yy]) return 0;
		for(int kk=0;kk<3;kk++){
			int xx0=xx+fx[xx&1][kk][0],yy0=yy+fx[xx&1][kk][1];
			if (xx0>=0&&yy0>=0&&(xx0!=x||yy0!=y)){
				if (bz[xx0][yy0])
					return 0;
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	int t=0,w=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&j,&k),j+=4,k+=2,a[j][k]=1;
		bz[j][k]=1,w++,d[w][0]=j,d[w][1]=k;
	}
	for(int x=0;x<maxn;x++) for(int y=0;y<maxn;y++) if (bz[x][y]){
		for(k=0;k<3;k++){
			int xx=x+fx[x&1][k][0],yy=y+fx[x&1][k][1];
			if (xx>=0&&yy>=0) 
				ans+=bz[x][y]!=bz[xx][yy];
		}
	}
	while (t<w){
		t++; int x=d[t][0],y=d[t][1];
		for(k=0;k<3;k++){
			int xx=x+fx[x&1][k][0],yy=y+fx[x&1][k][1];
			if (xx>=0&&yy>=0){
				cnt[xx][yy]++;
				if (!bz[xx][yy]&&cnt[xx][yy]>=2){
					bz[xx][yy]=1;
					w++,d[w][0]=xx,d[w][1]=yy;
				}
			}
		}
	}
	for(i=0;i<maxn;i++) for(j=0;j<maxn;j++) if (!vis[i][j]&&bz[i][j])
		dfs(i,j,-1,-1),ans-=2;
	for(i=0;i<maxn;i++) for(j=0;j<maxn;j++) if (bz[i][j]&&!a[i][j])
		ans-=check(i,j)*2;
	printf("RECOVERED\n");
	printf("%d\n",ans);
}