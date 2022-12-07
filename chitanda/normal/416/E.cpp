#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define oo ((int)1e9)

int n,m,dist[600][600],d[600][600],ru[600],ans[600];
int x,y,z;

int e,to[500000],ne[500000],he[600],we[500000];

int main(){
	memset(dist,127,sizeof(dist));
	memset(d,127,sizeof(d));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		d[x][y]=d[y][x]=dist[x][y]=dist[y][x]=z;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++) 
			if(i!=k)
				for(int j=1;j<=n;j++)
					if (j!=k && j!=i)
						if (dist[i][k]<oo && dist[k][j]<oo)
							if (dist[i][k]+dist[k][j]<dist[i][j])
								dist[i][j]=dist[i][k]+dist[k][j];
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=n;i++){
		memset(ru,0,sizeof(ru));
		memset(ans,0,sizeof(ans));
		for(int j=1;j<=n;j++) 
			if (dist[i][j]<oo)
				for(int k=1;k<=n;k++)
					if (d[j][k]<oo && j!=k)
						if (dist[i][j]+d[j][k]==dist[i][k]) ru[k]++;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if (dist[i][j]+dist[j][k]==dist[i][k]) ans[k]+=ru[j];
		for(int j=i+1;j<=n;j++) printf("%d ",ans[j]);
	}
	return 0;
}