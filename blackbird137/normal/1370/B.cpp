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

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=5005;
int t,n,a,j[N],o[N],tj,to,nj,no;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		tj=0,to=0;
		for(int i=1;i<=n*2;++i)
		{
			a=read();
			if(a%2==1) j[++tj]=i;
			else o[++to]=i;
		}
		nj=1,no=1;
		for(int i=1;i<=n-1;++i)
		{
			if(nj+2<=tj)
				printf("%d %d\n",j[nj],j[nj+1]),nj+=2;
			else
				printf("%d %d\n",o[no],o[no+1]),no+=2;
		}
	}
	return 0;
}