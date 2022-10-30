#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",n/10+(n%10>=9));
	}
	return 0;
}