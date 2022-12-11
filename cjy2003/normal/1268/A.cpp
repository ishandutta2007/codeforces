#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
char a[200020];
int b[200020];
int main()
{
	scanf("%d %d %s",&n,&k,a);
	printf("%d\n",n);
	for(int i=0;i<n;++i)a[i]-='0';
	for(int i=0;i<n;++i)b[i]=a[i%k];
	bool flag=0;
	for(int i=0;i<n;++i)
		if(a[i]!=b[i])
		{
			if(a[i]>b[i])flag=1;
			break;
		}
	if(!flag)
	{
		for(int i=0;i<n;++i)printf("%d",b[i]);
		return 0;
	}
	int x=k-1;
	while(b[x]==9)b[x]=0,--x;
	++b[x];
	for(int i=k;i<n;++i)b[i]=b[i%k];
	for(int i=0;i<n;++i)printf("%d",b[i]);
	return 0;
}