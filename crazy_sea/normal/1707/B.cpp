#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,T,c[N],b[N],len,s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		s=len=0;
		while(n>1)
		{
			sort(c+1,c+n+1);
			if(s)
			{
				s--;
				for(int i=1;i<=n;i++)
					b[i]=c[i]-c[i-1];
			}
			else
			{
				for(int i=1;i<n;i++) b[i]=c[i+1]-c[i];
				n--;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n;i++)
				if(b[i]==0) s++;
				else c[++len]=b[i];
			n=len,len=0;
		}
		if(n==1) printf("%d",c[1]);
		else printf("0");
		printf("\n");
	}
}