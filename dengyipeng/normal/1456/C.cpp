#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#define maxn 500005
#define ll long long 
using namespace std;

int n,m,i,j,k,res;
ll a[maxn],ans,sum;

int main(){
	scanf("%d%d",&n,&m),m++;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n),res=0;
	for(i=n;i>=1;i--){
		ans+=sum,sum+=a[i];
		if (sum<0) {
			a[i]=sum,res=i;
			break;
		}
	}
	ll d=0;
	for(i=1;i<=res;i++){
		ans+=a[i]*d;
		if (i%m==0) d++;
	}
	printf("%lld\n",ans);
}