#include<cstdio>
#include<algorithm>
using namespace std;

int n,b;
int ans;
int main()
{
	int x;
	scanf("%d%d",&b,&n); b&=1;
	for (int i=1;i<n;i++)
	{
		scanf("%d",&x);
		ans=(ans+b*(x&1))%2;
	}
	scanf("%d",&x);
	ans=(ans+(x&1))%2;
	puts(ans&1?"odd":"even");
	return 0;
}