#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define ll long long 
using namespace std;

int T,n,i,j,k,du[maxn],a[maxn],p[maxn];
int cmp(int i,int j){return a[i]>a[j];}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=i,du[i]=0;
		for(i=1;i<n;i++) scanf("%d%d",&j,&k),du[j]++,du[k]++;
		for(i=1;i<=n;i++) du[i]--;
		sort(p+1,p+1+n,cmp);
		ll sum=0;
		for(i=1;i<=n;i++) sum+=a[i];
		printf("%lld ",sum);
		for(i=1;i<=n;i++){
			int x=p[i];
			for(j=1;j<=du[x];j++)
				sum+=a[x],printf("%lld ",sum);
		}
		printf("\n");
	}
}