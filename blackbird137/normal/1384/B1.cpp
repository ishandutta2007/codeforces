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
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5;
int t,n,k,l,d[N],now,hi,flag;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();l=read();
		for(int i=1;i<=n;++i)
			d[i]=read();
		flag=1;hi=k;now=0;
		for(int i=1;i<=n;++i)
		{
			if(d[i]+k<=l) hi=k,now=0;
			else
			{
				if(now+d[i]>l)
				{
					flag=0;
					break;
				}
				if(hi!=0)
				{
					if(l-d[i]<hi) hi=l-d[i];
					else hi--;
					if(hi==0) now=1;
				}
				else now++;
				
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}