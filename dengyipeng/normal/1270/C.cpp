#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long 
using namespace std;

int T,n,i,j;
ll sum,xsum,a,x,tmp0,tmp1;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),sum=xsum=0;
		for(i=1;i<=n;i++) scanf("%lld",&a),sum+=a,xsum^=a;
		xsum<<=1,x=0;
		for(i=0;i<63;i++) if (sum!=xsum){
			if ((sum>>i&1)!=(xsum>>i&1))
				x|=1ll<<i,sum+=1ll<<i,xsum^=1ll<<i+1;
		} else break;
		if (xsum!=sum){
			printf("!!!");
		}
		printf("1\n%lld\n",x);
	}
}