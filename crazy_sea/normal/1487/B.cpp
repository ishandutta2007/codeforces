#include<cstdio>
using namespace std;
int T,n,k,x,y,s;
void print(int a)
{
	if(a%n==0) printf("%d\n",n);
	else printf("%d\n",a%n);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n&1)
		{
			k--;
			s=1+(k/(n/2))*((n/2)+1)%n;
			print(s+k%(n/2));
		}
		else print(k%n);
	}
}