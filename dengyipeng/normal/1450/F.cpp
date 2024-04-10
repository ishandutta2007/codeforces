#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;

int T,n,i,j,k,a[maxn],c[maxn],cnt,ans;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(c,0,sizeof(int)*(n+1));
		for(i=1;i<=n;i++) c[a[i]]++;
		int tp=1;
		for(i=1;i<=n;i++) if (c[i]>(n+1)/2){
			printf("-1\n"),tp=0;
			break;
		}
		if (!tp) continue;
		memset(c,0,sizeof(int)*(n+1));
		if (n==1) {printf("0\n");continue;}
		c[a[1]]++,c[a[n]]++,cnt=1;
		for(i=1;i<n;i++) if (a[i]==a[i+1]) 
			c[a[i]]++,c[a[i+1]]++,cnt++;
		ans=cnt;
		for(i=1;i<=n;i++) 
			ans=max(ans,cnt+(c[i]-2-(cnt*2-c[i])+1)/2);
		printf("%d\n",ans-1);
	}
}