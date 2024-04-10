#include <cstdio>

using namespace std;

int a,b,ans=1e9+1e8,n,m,i;

int main()
{
	scanf("%d%d",&n,&m);

	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(b-a+1 < ans) ans = b-a+1;
	}

	printf("%d\n",ans);
	for(i=0;i<n;i++){
		printf("%d ",i%ans);
	}

	return 0;
}