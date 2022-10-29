#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;

int T,n,i,j,k,p,a[maxn],x,y,f[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&p,&k);
		char ch=getchar();
		while (ch<'0'||ch>'9') ch=getchar();
		for(i=1;i<=n;i++) a[i]=ch-'0',ch=getchar();
		scanf("%d%d",&x,&y);
		for(i=n;i>=1;i--) f[i]=((i+k>n)?0:f[i+k])+(a[i]^1);
		int ans=2e9;
		for(i=p;i<=n;i++)
			ans=min(ans,(i-p)*y+f[i]*x);
		printf("%d\n",ans);
	}
}