#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a1,a2,a3,a4,a5,a6;
	scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
	
	int F = a1+a2+a3;
	printf("%d\n",F*F-a1*a1-a3*a3-a5*a5);
	
	return 0;
}