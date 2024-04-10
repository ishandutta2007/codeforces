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

const int N=105;
int t,n,a[N],ans;

map<int,int> mp;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		ans=0;
		for(int s=2;s<=2*n;++s)
		{
			int tmp=0;
			mp.clear();
			for(int i=1;i<=n;++i)
				mp[a[i]]++;
			for(int i=1;i<=n;++i)
				if(a[i]==s-a[i]&&mp[a[i]]>=2)
				{
					mp[a[i]]-=2;
					tmp++;
				}
				else if(a[i]!=s-a[i]&&mp[a[i]]&&mp[s-a[i]])
				{
					mp[a[i]]--;
					mp[s-a[i]]--;
					tmp++;
				}
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}