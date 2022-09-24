#include <bits/stdc++.h>

using namespace std;

int k,m=1e9,a,b,n,i;

int main()
{
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		m=min(m,b);
		k+=m*a;
	}
	
	printf("%d\n",k);
	
	return 0;
}