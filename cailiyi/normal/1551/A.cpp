#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d %d\n",n/3+(n%3==1),n/3+(n%3==2));
	}
	return 0;
}