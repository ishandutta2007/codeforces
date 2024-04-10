#include <cstdio>

using namespace std;

long long a,d;

int main()
{
	scanf("%I64d",&a);

	if(a<3){
		printf("-1\n");
		return 0;
	}
	
	d=1;
	while(a%(d*2)==0) d*=2;

	if(a==d){
		printf("%I64d %I64d\n",d/4*3,d/4*5);
		return 0;
	}

	printf("%I64d %I64d\n",(a/d)*(a/d)/2*d,((a/d)*(a/d)+1)/2*d);

	return 0;
}