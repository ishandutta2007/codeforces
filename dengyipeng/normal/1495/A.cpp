#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 100005
#define db double
using namespace std;

int T,n,i,j,k,a[maxn],b[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),a[0]=0,b[0]=0;
		for(i=1;i<=2*n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if (x==0) a[++a[0]]=abs(y);
			else b[++b[0]]=abs(x);
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		db ans=0;
		for(i=1;i<=n;i++)
			ans+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
		printf("%.11lf\n",ans);
	}
}