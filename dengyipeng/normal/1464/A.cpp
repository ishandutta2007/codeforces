#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
using namespace std;

int T,n,m,i,j,k,fa[maxn],a[maxn][2];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) fa[i]=i;
		int ans=m;
		for(i=1;i<=m;i++) {
			scanf("%d%d",&j,&k);
			if (j==k) ans--; else 
			if (father(j)==father(k)) ans++;
			else fa[father(j)]=father(k);
		}
		printf("%d\n",ans);
	}
}