#include<cstdio>
#include<algorithm>
using namespace std;
long long a[300001];
int main(){
	long long n,k,p,i,j=1;
	scanf("%lld%lld%lld",&n,&p,&k);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		long long t=a[i]*a[i]%p;
		a[i]=(t*t%p-k*a[i]%p+p*p)%p;
	}
	sort(a,a+n);
	i=0;
	long long ans=0;
	while(i<n){
		while(j<n&&a[i]==a[j]){
			j++;
		}
		ans+=(j-i-1)*(j-i)/2;
		i=j;
		j++;
	}
	printf("%lld",ans);
	return 0;
}