#include<bits/stdc++.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(((n&1)^((n>>4)&1))==1)n^=17;
	if((((n>>2)&1)^((n>>3)&1))==1)n^=12;
	printf("%d\n",n);
	return 0;
}