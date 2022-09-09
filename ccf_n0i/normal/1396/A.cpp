#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,j;
long long a[100005],t;
string st;
int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&a[i]);
	if(n==1){
		puts("1 1\n0");
		puts("1 1\n0");
		printf("1 1\n%lld\n",-a[1]);
		return 0;
	}
	printf("%d %d\n",1,n);
	rep(i,n){
		long long tmp=a[i]%(n-1);
		if(tmp<0) tmp+=n-1;
		tmp=n-1-tmp;
		a[i]+=tmp*n;
		printf("%lld%c",tmp*n,(i==n?'\n':' '));
	}
	printf("%d %d\n",1,n-1);
	rep(i,n-1){
		printf("%lld%c",-a[i],(i==n-1?'\n':' '));
	}
	printf("%d %d\n%lld\n",n,n,-a[n]);
	return 0;
}