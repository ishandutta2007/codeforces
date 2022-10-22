#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5,M=1e9;
int t,a[N],n,tot,ans;

int main()
{
	a[1]=2;
	for(tot=2;a[tot-1]<=M;++tot)
		a[tot]=a[tot-1]+tot-1+tot*2;
	tot--;
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		while(n>=2)
		{
			int pos=upper_bound(a+1,a+1+tot,n)-a-1;
			n-=a[pos];ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}