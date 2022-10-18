#include<stdio.h>
#define MIN(A, B) ((A)<(B)?(A):(B))

int main()
{
	int n, m, r, c;

	scanf("%d%d",&n,&m);

	r = 0, c = m;
	printf("%d\n", MIN(n,m)+1);
	while(1)
	{
		printf("%d %d\n",r, c);
		r++;
		c--;

		if(r>n || c<0) break;

	}

	return 0;
}