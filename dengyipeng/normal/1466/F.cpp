#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 500005
#define ll long long 
#define mo 1000000007
using namespace std;

int n,m,i,j,k,fa[maxn],g[maxn],d[maxn];
ll ans;
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}

int main(){
	scanf("%d%d",&n,&m),ans=1;
	for(i=1;i<=m;i++) fa[i]=i,g[i]=0;
	for(i=1;i<=n;i++){
		int x,y; scanf("%d",&k);
		if (k==1){
			scanf("%d",&x),x=father(x);
			if (g[x]==0) d[++d[0]]=i,g[x]=1,ans=ans*2%mo;
		} else {
			scanf("%d%d",&x,&y);
			x=father(x),y=father(y);
			if (x!=y) {
				if (g[x]&&g[y]) continue;
				d[++d[0]]=i,fa[x]=y,g[y]|=g[x],ans=ans*2%mo;
			}
		}
	}
	printf("%lld %d\n",ans,d[0]);
	for(i=1;i<=d[0];i++) printf("%d ",d[i]);
}