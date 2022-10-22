#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#define fan(x) (x=='0'?'1':'0')

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int t,n,len,ans[N*3];
char a[N],b[N];

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s%s",a+1,b+1);
		len=0;
		for(int i=n;i>=1;--i)
			if(a[i]!=b[i])
			{
				if(a[1]!=fan(b[i]))
					ans[++len]=1,a[1]=fan(a[1]);
				for(int j=1;j<=i/2;++j)
				{
					swap(a[j],a[i-j+1]);
					a[j]=fan(a[j]);
					a[i-j+1]=fan(a[i-j+1]);
				}
				if(i%2==1) a[i/2+1]=fan(a[i/2+1]);
				ans[++len]=i;
			}
		printf("%d ",len);
		for(int i=1;i<=len;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}