#include<cstdio>
using namespace std;
int n,T,s,a;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a),s+=a;
		printf("%d\n",(s%n!=0));
		s=0;
	}
}