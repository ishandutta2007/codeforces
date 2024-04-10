#include <cstdio>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

long long n,a,b,p,s,e;

int main()
{
	scanf("%lld",&n);

	s = -1e10, e = 1e10;

	for(;n--;){
		scanf("%lld %lld",&a,&b);
		if(b==1) s = max(s,1900-p);
		else e = min(e,1899-p);
		p += a;
	}

	if(e == 1e10) printf("Infinity\n");
	else if(s>e) printf("Impossible\n");
	else printf("%lld\n",e+p);

	return 0;
}