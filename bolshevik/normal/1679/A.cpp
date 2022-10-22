#include<cstdio>
using namespace std;
int T;long long n;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld",&n);
		if(n%2||n==2){printf("-1\n");continue;}
		printf("%lld %lld\n",(n+4)/6,n/4);
	}
	return 0;
}