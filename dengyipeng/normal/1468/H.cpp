#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int T,n,m,K,i,j,k,bz[maxn],cnt[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&k,&m);
		for(i=1;i<=n;i++) bz[i]=0;
		for(i=1;i<=m;i++){
			int x; scanf("%d",&x);
			bz[x]=1;
		}
		if ((n-m)%(k-1)!=0) {
			printf("NO\n");
			continue;
		}
		for(i=1;i<=n;i++) cnt[i]=cnt[i-1]+(bz[i]^1);
		int tp=0;
		for(i=1;i<=n;i++) if (bz[i]){
			if (cnt[i]>=k/2&&cnt[n]-cnt[i]>=k/2){
				tp=1;
				printf("YES\n");
				break;
			}
		}
		if (!tp) printf("NO\n");
	}
}