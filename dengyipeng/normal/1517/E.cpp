#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
#define maxm 15000005
#define ll long long
#define mo 998244353
#define M 1e15
using namespace std;

int T,n,i,j,k,a[maxn];

int tot,t[maxm],tl[maxm],tr[maxm];
int newnode(){tot++,t[tot]=tl[tot]=tr[tot]=0;return tot;}
void add(int &x,ll l,ll r,ll p){
	if (!x) x=newnode(); t[x]++;
	if (l==r) return;
	ll mid=(l+r)>>1;
	if (p<=mid) add(tl[x],l,mid,p); 
	else add(tr[x],mid+1,r,p);
}
int find(int x,ll l,ll r,ll L,ll R){
	if (!x||l>R||r<L) return 0;
	if (L<=l&&r<=R) return t[x];
	ll mid=(l+r)>>1;
	return find(tl[x],l,mid,L,R)+find(tr[x],mid+1,r,L,R);
}

ll pre[maxn],nex[maxn],sum[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),tot=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) pre[i]=pre[i-1]-a[i];
		nex[n+1]=0;
		for(i=n;i>=1;i--) nex[i]=nex[i+1]+a[i];
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+((i&1)?1:-1)*a[i];
		tot=0; int rt=0;
		ll ans=0;
		for(i=0;i<=n;i+=2){
			add(rt,-M,M,pre[i]-sum[i]);
			if (i>=3) add(rt,-M,M,pre[i]+a[1]*2-sum[i]);
			ans+=find(rt,-M,M,-(nex[i+1]+sum[i])+1,M);
			if (i<=n-3) ans+=find(rt,-M,M,-(nex[i+1]-a[n]*2+sum[i])+1,M);
		}
		tot=rt=0;
		for(i=1;i<=n;i+=2){
			add(rt,-M,M,pre[i]+sum[i]);
			if (i>=3) add(rt,-M,M,pre[i]+a[1]*2+sum[i]);
			ans+=find(rt,-M,M,-(nex[i+1]-sum[i])+1,M);
			if (i<=n-3) ans+=find(rt,-M,M,-(nex[i+1]-a[n]*2-sum[i])+1,M);
		}
		for(i=2;i<=n-2;i++) if (pre[i]+nex[i+1]<0) ans++;
		printf("%lld\n",ans%mo); 
	}
}