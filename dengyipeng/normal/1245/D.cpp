#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 2005
#define ll long long 
using namespace std;

int n,i,j,k,fa[maxn],tot,u,v;
ll x[maxn],y[maxn],c[maxn],K[maxn],ans;
struct edge{int x,y,tp; ll z;} a[maxn*maxn];
int cmp(edge a,edge b){return a.z<b.z;}
int cp,p[maxn],cq,q[maxn][2];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	for(i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(i=1;i<=n;i++) scanf("%lld",&K[i]);
	for(i=1;i<=n;i++)
		tot++,a[tot].x=0,a[tot].y=i,a[tot].z=c[i],a[tot].tp=1;
	for(i=1;i<=n;i++) for(j=2;j<=n;j++) 
		tot++,a[tot].x=i,a[tot].y=j,a[tot].z=(K[i]+K[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),a[tot].tp=2;
	sort(a+1,a+1+tot,cmp);
	for(i=0;i<=n;i++) fa[i]=i;
	int cnt=0;
	for(i=1;i<=tot;i++){
		u=father(a[i].x),v=father(a[i].y);
		if (u!=v){
			cnt++,fa[u]=v,ans+=a[i].z;
			if (a[i].tp==1) p[++cp]=a[i].y;
			else q[++cq][0]=a[i].x,q[cq][1]=a[i].y;
			if (cnt==n) break;
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",cp);
	for(i=1;i<=cp;i++) printf("%d ",p[i]);
	printf("\n%d\n",cq);
	for(i=1;i<=cq;i++) printf("%d %d\n",q[i][0],q[i][1]);
}