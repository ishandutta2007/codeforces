#include <cstdio>

using namespace std;

long long a,b,x,y,z;

int main()
{
	scanf("%I64d",&a);

	x=1,y=2;

	while(a){
		if(y>a){
			printf("%I64d\n",b);
			break;
		}
		b++;
		z=y,y=x+y,x=z;
	}

	return 0;
}