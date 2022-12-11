#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,k;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		if(n/k>=m)printf("%d\n",m);
		else printf("%d\n",n/k-(m-1-n/k)/(k-1)-1);
	}
	return 0;
}