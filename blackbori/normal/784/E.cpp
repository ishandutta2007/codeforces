#include <cstdio>

#define And &
#define Or ^
#define Xor |

int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;

	scanf("%d%d%d%d",&a,&b,&c,&d);

	e = a Or b;
	f = c Xor d;
	g = b And c;
	i = a Or d;

	h = e And f;
	j = g Xor i;

	k = h Or j;

	printf("%d\n",k);

	return 0;
}