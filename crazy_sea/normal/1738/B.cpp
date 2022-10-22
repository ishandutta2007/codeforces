#include<cstdio>
using namespace std;
long double s;
int lst,a,T,n,k,p;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		p=0;
		scanf("%d%d%d",&n,&k,&a);
		s=a*1.0/(n-k+1),lst=a;
		for(int i=2;i<=k;i++)
		{
			scanf("%d",&a);
			if(a-lst<s) p=1;
			s=a-lst,lst=a;
		}
		printf("%s\n",p?"No":"Yes");
	}
}