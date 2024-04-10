#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
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

const int N=5e4+5;
int t,n,a[N],b[N]; 

map<int,int> mp;

signed main()
{
	t=read();
	while(t--)
	{
		mp.clear();
		n=read();
		int flag=1,flag2=1;
		for(int i=1;i<=n;++i)
		{
			a[i]=b[i]=read();
			if(mp[a[i]])
				flag2=0;
			mp[a[i]]=1;
		}
			
		if(!flag2)
		{
			printf("YES\n");
			continue;
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
			if(a[n-i+1]!=b[i])
			{
				flag=0;
				break;
			}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}