#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long f[200005][2],b[200005];
struct node{
	long long val;
	int id;
	node(){id=val=0;};
}a[200005];
int pre[200005];
bool cmp1(node x,node y){
	return x.val==y.val?x.id<y.id:x.val<y.val;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}
int main(){
	int T,n,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%lld",&a[i].val);
			b[i]=a[i].val;
			a[i].val+=a[i-1].val;
			a[i].id=i;
			f[i][0]=f[i][1]=0;
		}
		sort(a+1,a+1+n,cmp1);
		for(i=1;i<=n;++i){
			pre[a[i].id]=(a[i-1].val==a[i].val)?a[i-1].id:-1;
			if(a[i].val==0)pre[a[i].id]=max(0,pre[a[i].id]);
		}
		sort(a+1,a+1+n,cmp2);
		/*for(i=1;i<=n;++i)printf("%d ",pre[i]);
		puts("");*/
		f[0][0]=1;f[0][1]=0;
		for(i=1;i<=n;++i){
			if(b[i]==0){
				f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
				f[i][1]=f[i-1][1];
			}
			else{
				if(pre[i]>=0)f[i][0]=(f[pre[i]][0]+f[pre[i]][1])%mod;
				else f[i][0]=0;
				f[i][1]=(f[i-1][0]+2*f[i-1][1]-f[i][0]+mod)%mod;
			}
		}
		/*for(i=1;i<=n;++i){
			printf("%lld %lld\n",f[i][0],f[i][1]);
		}*/
		printf("%lld\n",(f[n][0]+f[n][1])%mod);
	}
	return 0;
}