#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,i;
	
	scanf("%d",&n);
	
	if(n < 6){
		printf("-1\n");
	}
	else{
		for(i=1;i<=n-6;i++) printf("%d %d\n",i,i+1);
		printf("%d %d\n",n-5,n-4);
		printf("%d %d\n",n-5,n-3);
		printf("%d %d\n",n-5,n-2);
		printf("%d %d\n",n-4,n-1);
		printf("%d %d\n",n-4,n);
	}
	
	for(i=1;i<n;i++) printf("%d %d\n",i,i+1);
	
	return 0;
}