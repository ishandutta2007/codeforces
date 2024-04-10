#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define maxn 505
#define ll long long 
#define mo 998244353
using namespace std;

int T,n,i,j,k,a[maxn*2][maxn],c[maxn][maxn],bz[maxn*2],used[maxn*2];
vector<int> d[maxn][maxn];
int D[maxn*maxn][2],t,w;
void del(int x){
	static int Q[maxn*2]; int head=0,tail=0;
	bz[x]=1;
	for(int i=1;i<=n;i++){
		c[i][a[x][i]]--;
		if (c[i][a[x][i]]==1) w++,D[w][0]=i,D[w][1]=a[x][i];
		for(int j=0;j<d[i][a[x][i]].size();j++){
			int y=d[i][a[x][i]][j];
			if (!bz[y]) Q[++tail]=y,bz[y]=1;
		}
	}
	while (head<tail){
		x=Q[++head];
		for(int i=1;i<=n;i++){
			c[i][a[x][i]]--;
			if (c[i][a[x][i]]==1) w++,D[w][0]=i,D[w][1]=a[x][i];
		}	
	}
}

int fa[maxn*2],g[maxn*2];
int father(int x){
	if (fa[x]==x) return x;
	int y=fa[x]; fa[x]=father(y),g[x]^=g[y];
	return fa[x];
}
void link(int x,int y){
	if (father(x)==father(y)&&g[x]==g[y])
		printf("!!");
	else {int z=father(y); fa[z]=father(x),g[z]=g[y]^g[x]^1;}
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(used,0,sizeof(used));
		memset(bz,0,sizeof(bz));
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) d[i][j].clear();
		for(i=1;i<=2*n;i++) for(j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			c[j][a[i][j]]++,d[j][a[i][j]].push_back(i);
		}
		t=w=0;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (c[i][j]==1)
			w++,D[w][0]=i,D[w][1]=j;
		while (t<w){
			t++; int x=D[t][0],v=D[t][1];
			if (c[x][v]==1){
				for(i=0;i<d[x][v].size();i++)
					if (!bz[d[x][v][i]]) 
						used[d[x][v][i]]=1,del(d[x][v][i]);
			}
		}
		for(i=1;i<=2*n;i++) fa[i]=i,g[i]=0;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if (c[i][j]>0)
			for(k=0;k<d[i][j].size();k++){
				int x=d[i][j][k];
				if (bz[x]) continue;
				for(int l=k+1;l<d[i][j].size();l++){
					int y=d[i][j][l];
					if (!bz[y])
						link(x,y);
				}
				break;
			}
		ll ans=1;
		for(i=1;i<=n*2;i++) if (!bz[i])
			fa[i]=father(i),ans=(fa[i]==i)?(ans*2%mo):ans;
		printf("%lld\n",ans);
		for(i=1;i<=n*2;i++)	if (bz[i]&&used[i]||!bz[i]&&g[i]) printf("%d ",i);
		printf("\n");
	}
}