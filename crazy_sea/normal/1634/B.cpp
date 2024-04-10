#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,a,s,T;
long long y;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld",&n,&x,&y);
		for(int i=1;i<=n;i++) scanf("%d",&a),s=(s+a)%2;
		if(((y-x)%2+2)%2==s) printf("Alice");
		else printf("Bob");
		printf("\n");
		s=0;
	}
}