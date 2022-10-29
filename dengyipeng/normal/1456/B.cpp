#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
#define maxp 31
using namespace std;

int n,i,j,k,a[maxn],cnt[maxp],sum[maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	for(i=0,j=1;i<=30;i++) {
		while (j<=n&&(a[j]>>i+1)==0)
			cnt[i]++,j++;
	}
	for(i=0;i<=30;i++) if (cnt[i]>=3){
		printf("1\n");
		exit(0);
	}
	int ans=2e9;
	for(i=1;i<n;i++) for(j=i;j>=1;j--) for(k=i+1;k<=n;k++)
		if ((sum[i]^sum[j-1])>(sum[k]^sum[i])){
			ans=min(ans,i-j+k-i-1);
		}
	if (ans>=2e9)
		printf("-1");
	else printf("%d\n",ans);
}