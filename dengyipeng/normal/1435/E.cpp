#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std;

int T;
ll a,b,c,d;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a-b*c>0) {printf("-1\n");continue;}
		if (d>=c) {
			if (a-b*c>0) printf("-1\n");
			else printf("%lld\n",a);
			continue;
		}
		ll v=c/d,s=c-v*d,k=(s+c)*(v+1)/2*b;
		if (k<a) {printf("-1\n");continue;}
		k=a/(b*d);
		k=min(k,c/d);
		printf("%lld\n",a*(k+1)-(k+1)*k/2*b*d);
	}
}