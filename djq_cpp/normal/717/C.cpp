#include<algorithm>
#include<cstdio>
using namespace std;
long long n,a[100005],b[100005],res;
int main(){
	scanf("%I64d",&n);
	long long xb;
	for(xb=0;xb<n;xb++) scanf("%I64d",&a[xb]);
	for(xb=0;xb<n;xb++) b[xb]=-a[xb];
	sort(a,a+n);
	sort(b,b+n);
	for(xb=0;xb<n;xb++){
		res-=(long long)b[xb]*a[xb];
		res%=10007;
	}
	printf("%I64d",res);
	return 0;
}