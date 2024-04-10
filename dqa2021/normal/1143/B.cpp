#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

ll ans;
int n;
ll cnt(int x)
{
	if (x>9) return cnt(x/10)*(x%10);
	return x%10;
}
ll tmp;
int main()
{
	scanf("%d",&n);
	ans=cnt(n);
	tmp=10;
	while (true)
	{
		if (n/(tmp/10)%10==9){tmp*=10;continue;}
		if (n<tmp) break;
		n-=tmp;
		n+=-(n/(tmp/10)%10*(tmp/10))+(9*(tmp/10));
//		printf("get %d\n",n);
		ans=max(ans,cnt(n));
		tmp*=10;
	}
	printf("%I64d\n",ans);
	return 0;
}