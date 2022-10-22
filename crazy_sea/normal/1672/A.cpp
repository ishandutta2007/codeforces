#include<cstdio>
using namespace std;
int n,T,a,s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a),a--,s^=a;
		printf("%s\n",(s&1)?"errorgorn":"maomao90");
		s=0;
	}
}