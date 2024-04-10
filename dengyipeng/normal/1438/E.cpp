#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define ll long long 
using namespace std;

int n,i,j,k,ans;
ll sum[maxn],a[maxn];

int merge(int l,int r,ll p){
	int ans=-1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (sum[mid]<p) l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}

void check(int l,int r){
	if (r-l<=1) return;
	if ((a[l]^a[r])==sum[r-1]-sum[l])
		ans++;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	for(i=1;i<n;i++){
		k=merge(i+1,n-1,sum[i]+a[i]);
		if (k>0) check(i,k+1);
		for(j=0;j<=30;j++) if (a[i]>>j&1^1){
			k=merge(i+1,n-1,sum[i]+(((a[i]>>j)+2)<<j));
			if (k<0) continue;
			if (sum[k]-sum[i]>=(a[i]>>j^1)<<j)
				check(i,k+1);
		}
	}
	printf("%d\n",ans);
}