#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;
LL n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	if(m>=n)printf("%lld\n",n);
	else{
		LL l=0LL,r=1LL<<31;
		while(l<r){
			LL mid=(l+r)>>1;
			if(m+((mid*(mid+1))>>1)<n)l=mid+1;else r=mid;
		}
		printf("%lld\n",m+l);
	}
	return 0;
}