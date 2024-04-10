#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int n,i,j,k,a[maxn],bz[maxn],d[2][maxn];
int tot,ans[maxn][2],c[maxn];

void cover(int x,int t){
	d[t][0]=0;
	while (!bz[x]) d[t][++d[t][0]]=x,bz[x]=1,x=a[x];
}

void add(int x,int y){
	tot++,ans[tot][0]=x,ans[tot][1]=y;
	swap(a[x],a[y]),c[a[x]]^=1,c[a[y]]^=1;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	int tp=0;
	for(i=1;i<=n;i++) if (!bz[i]){
		cover(i,tp);
		if (tp){
			for(j=1;j<=d[1][0];j++)
				add(d[0][1],d[1][j]);
			for(j=2;j<=d[0][0];j++)
				add(d[0][j],d[1][1]);
			add(d[0][1],d[1][1]);
			tp=0;
		} else tp=1;
	}
	if (tp){
		if (d[0][0]==n){
			add(d[0][1],d[0][n]);
			add(d[0][1],d[0][2]);
			add(d[0][2],d[0][n]);
			for(i=3;i<=n;i++) add(d[0][1],d[0][i]);
		} else {
			for(i=1;i<=d[0][0];i++) add(1,d[0][i]);
			add(1,d[0][1]);
		}
	}
	for(i=1;i<=n;i++) if (a[i]!=i||c[i])
		printf("!");
	printf("%d\n",tot);
	for(i=1;i<=tot;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
}