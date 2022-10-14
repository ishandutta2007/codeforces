#include<bits/stdc++.h>
using namespace std;
int px[100003],py[100003];
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2) return 0*printf("No");
	else
	{
		for(int i=1; i<=n; i++) scanf("%d%d",&px[i],&py[i]);
		int x=px[1]+px[n/2+1],y=py[1]+py[n/2+1];
		for(int i=2; i<=n/2; i++) if(x!=px[i]+px[n/2+i] || y!=py[i]+py[n/2+i]) return 0*printf("No");
		printf("Yes");
	}
	return 0;
}