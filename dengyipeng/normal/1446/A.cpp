#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
#define ll long long 
using namespace std;

int T,n,i,j,k,bz[maxn],cnt,p[maxn];
ll a[maxn],s;
int cmp(int i,int j){return a[i]>a[j];}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%lld",&n,&s);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]),p[i]=i,bz[i]=0;
		sort(p+1,p+1+n,cmp);
		ll sum=0; cnt=0;
		for(i=1;i<=n;i++) if (sum+a[p[i]]<=s) 
			sum+=a[p[i]],bz[p[i]]=1,cnt++;
		else bz[p[i]]=0;
		if (sum>=(s+1)/2) {
			printf("%d\n",cnt);
			for(i=1;i<=n;i++) if (bz[i]) printf("%d ",i);
			printf("\n");
		} else printf("-1\n");
	}
}