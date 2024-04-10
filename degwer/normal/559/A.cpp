#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if((f+a+b!=b+c+d)||(b+c+d!=d+e+f))printf("0\n");
	else printf("%d\n",(d+e+f)*(d+e+f)-b*b-d*d-f*f);
}