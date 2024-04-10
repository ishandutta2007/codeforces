#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 500005
#define ll long long 
using namespace std;

int n,m,d,i,j,k,a[maxn],b[maxn],t[maxn*2];
ll lcm,D[maxn],K;

int gcd(int x,int y){return (x%y==0)?y:gcd(y,x%y);}

void exgcd(ll x,ll y,ll &a,ll &b){
	if (!y) {a=1,b=0;return;}
	exgcd(y,x%y,a,b);
	ll t=b; b=a-x/y*b,a=t;
}
ll count(ll N){
	ll sum=N-D[0]*(N/lcm);
	for(int i=1;i<=D[0];i++) if (D[i]&&D[i]<=N%lcm)
		sum--;
	return sum;
}

int main(){
	scanf("%d%d%lld",&n,&m,&K),d=gcd(n,m);
	ll A=n/d,B=m/d,x,y; lcm=1ll*n*m/d;
	exgcd(A,B,x,y);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),t[a[i]]=i;
	for(i=1;i<=m;i++) {
		scanf("%d",&b[i]);
		if (t[b[i]]){
			ll X=t[b[i]],Y=i;
			if ((Y-X)%d==0){
				ll xx=x*((Y-X)/d);
				xx=((xx*n+t[b[i]])%lcm+lcm)%lcm;
				D[++D[0]]=xx;
			}
		}
	}
	ll l=0,r=1e18,mid,ans=r;
	while (l<=r){
		mid=(l+r)>>1;
		if (count(mid)>=K) 
			r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}