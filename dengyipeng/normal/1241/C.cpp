#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define ll long long 
using namespace std;

int q,n,i,j,a,b,ans;
ll p[maxn],s[maxn],x,y,k,sum,c,g;
int cmp(ll a,ll b){return a>b;}

int gcd(int x,int y){return (x%y==0)?y:gcd(y,x%y);}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&q);
	while (q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		scanf("%I64d%d%I64d%d%I64d",&x,&a,&y,&b,&k);
		if (x<y) swap(x,y),swap(a,b);
		sort(p+1,p+1+n,cmp);
		for(i=1;i<=n;i++) s[i]=s[i-1]+p[i];
		g=1ll*a*b/gcd(a,b);
		for(ans=1;ans<=n;ans++){
			c=sum=0;
			sum+=(s[c+ans/g]-s[c])/100*(x+y),c+=ans/g;
			sum+=(s[c+ans/a-ans/g]-s[c])/100*x,c+=ans/a-ans/g;
			sum+=(s[c+ans/b-ans/g]-s[c])/100*y,c+=ans/b-ans/g;
			if (sum>=k) {
				printf("%d\n",ans);
				break;
			}
		}
		if (ans>n) printf("-1\n");
	}
}