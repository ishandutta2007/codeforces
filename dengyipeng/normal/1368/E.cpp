#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200005
using namespace std;

int T,n,m,i,j,k,bz[maxn],c[3];
int em,e[maxn*2],nx[maxn*2],ls[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		em=0,memset(ls,0,sizeof(int)*(n+1));
		for(i=1;i<=m;i++){
			int x,y; scanf("%d%d",&x,&y);
			em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
		}
		int cnt=0;
		for(int x=1;x<=n;x++){
			c[0]=c[1]=c[2]=0;
			for(i=ls[x];i;i=nx[i]) c[bz[e[i]]]++;
			if (c[1]) bz[x]=2; else
			if (c[0]) bz[x]=1; else 
				bz[x]=0;
			cnt+=bz[x]==2;
		}
		printf("%d\n",cnt);
		for(i=1;i<=n;i++) if (bz[i]==2) printf("%d ",i);
		printf("\n");
	}
}