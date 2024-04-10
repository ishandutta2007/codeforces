#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#define maxn 400005
using namespace std;

int n,i,j,k,a[maxn],x,y;
struct arr{
	int c,d;
} q[maxn];
int tot,sum[maxn];
int ans,ansi,ansk,w,h;
map<int,int> p[maxn];
int cmp2(arr a,arr b){return a.c<b.c;}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i=j) {
		tot++,q[tot].d=a[i];
		for(j=i;j<=n&&a[j]==a[i];j++) q[tot].c++;
	}
	sort(q+1,q+1+tot,cmp2);
	for(i=1;i<=tot;i++) sum[i]=sum[i-1]+q[i].c;
	k=tot;
	for(i=sqrt(n);i>=1;i--) {
		while (q[k].c>i) k--;
		w=i,h=(sum[k]+(tot-k)*i)/i;
		if (w*h>ans&&h>=w){
			ans=i*((sum[k]+(tot-k)*i)/i);
			ansi=i,ansk=k;
		}
	}
	printf("%d\n",ans);
	w=ansi,h=(sum[ansk]+(tot-ansk)*ansi)/ansi;
	printf("%d %d\n",w,h);
	x=y=0; int cnt=0;
	for(i=tot;i>=1;i--) {
		for(j=(i>ansk)?ansi:q[i].c;j;j--){
			p[x][y]=q[i].d;
			x=(x+1)%w,y=(y+1)%h;
			if (p[x][y]) x=(x+1)%w;
			if (++cnt==ans)
				break;
		}
		if (cnt==ans) break;
	}
	for(i=0;i<w;i++,printf("\n")) for(j=0;j<h;j++)
		printf("%d ",p[i][j]);
}