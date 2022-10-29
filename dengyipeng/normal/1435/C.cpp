#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;

const int m=6;
int n,i,j,k,a[m+1],b[maxn],c[maxn],tot;
struct arr{int x,v;} p[maxn*m+1];
int cmp(arr a,arr b){return a.v>b.v;}

int main(){
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		for(j=1;j<=m;j++) 
			tot++,p[tot].x=i,p[tot].v=b[i]-a[j];
	}
	sort(p+1,p+1+tot,cmp);
	int mi=b[1]-a[1],ans=2e9;
	for(i=1;i<=n;i++) mi=min(mi,b[i]-a[1]),c[i]=1;
	for(i=1;i<=tot;i=j){
		ans=min(ans,p[i].v-mi);
		int tp=0;
		for(j=i;j<=tot&&p[j].v==p[i].v;j++)	{
			if (c[p[j].x]==m) {tp=1;break;}
			c[p[j].x]++;
			mi=min(mi,b[p[j].x]-a[c[p[j].x]]);
		}
		if (tp) break;
	}
	printf("%d",ans);
}