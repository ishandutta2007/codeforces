#include<cstdio>
using namespace std;
int T,a,b,c;long long x,y,z;
int main(){
	for(scanf("%d",&T);T--;printf("%lld %lld %lld\n",x,y,z)){
		scanf("%d%d%d",&a,&b,&c);
		if(a>b&&a>c) x=a,z=a+c,y=a+b+c;
		else if(b>a&&b>c) y=b,x=b+a,z=a+b+c;
		else z=c,y=b+c,x=a+b+c;
	}
	return 0;
}