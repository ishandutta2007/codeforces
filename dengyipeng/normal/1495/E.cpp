#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5000005
#define ll long long
#define mo 1000000007
using namespace std;

int n,i,j,k,st,tot,d[maxn],L[maxn],R[maxn];
ll t[maxn],a[maxn],b[maxn],c[2];

void read(){
	int m,pre=0;
	scanf("%d",&m);
	while (m--){
		int R,k; ll sd,bs;
		scanf("%d%d%lld%lld",&R,&k,&sd,&bs);
		for(i=pre+1;i<=R;i++){
			t[i]=sd%2;
			sd=(sd*bs+233)%mo;
			a[i]=sd%k+1;
			sd=(sd*bs+233)%mo;
		}
		pre=R;
	}
}

int main(){
	scanf("%d",&n),read();
	for(i=1;i<=n;i++) b[i]=a[i];
	a[1]--;
	for(i=1;i<=n;i++) c[t[i]]+=a[i];
	for(i=2;i<=n;i++) if (t[i]!=t[1]){st=i;break;}
	if (i<=n){
		d[tot=1]=st,L[tot]=st,R[tot]=st;
		for(i=st%n+1;i!=st;i=i%n+1) if (a[i]){
			if (t[i]==t[d[tot]]) R[tot]=i; else
				tot++,d[tot]=L[tot]=R[tot]=i;
		}
		if (c[t[st]]>c[t[st]^1]) a[st]--,k=t[st]^1;
		else k=t[st];
		i=1; ll sum=0;
		for(int cnt=1;cnt<=tot*2;cnt++,i=i%tot+1){
			if (t[d[i]]==k){
				while (L[i]!=R[i]) {
					sum+=a[L[i]],a[L[i]]=0;
					L[i]=L[i]%n+1;
				}
				sum+=a[R[i]],a[R[i]]=0;
			} else {
				while (sum&&L[i]!=R[i]){
					ll tmp=min(a[L[i]],sum);
					a[L[i]]-=tmp,sum-=tmp;
					if (!a[L[i]]) L[i]=L[i]%n+1;
				}
				if (L[i]==R[i]){
					ll tmp=min(a[R[i]],sum);
					a[R[i]]-=tmp,sum-=tmp;
				}
			}
		}
	}
	ll ans=1;
	for(i=1;i<=n;i++) 
		(ans*=(((b[i]-a[i])^(1ll*i*i))+1)%mo)%=mo;
	printf("%lld\n",ans);
}