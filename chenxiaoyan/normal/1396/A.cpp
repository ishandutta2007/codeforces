/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000;
int n;
int a[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	if(n==1){
		printf("1 1\n%lld\n1 1\n0\n1 1\n0\n",-a[1]);
		return 0;
	}
	printf("1 1\n%lld\n",-a[1]);
	printf("%lld %lld\n",2ll,1ll*n);
	for(int i=2;i<=n;i++)printf("%lld ",a[i]*(n-1));puts("");
	printf("%lld %lld\n",1ll,1ll*n);
	for(int i=1;i<=n;i++)printf("%lld ",i==1?0:-a[i]*n);
	return 0;
}