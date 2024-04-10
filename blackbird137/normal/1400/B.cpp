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

const int N=2e5+5;
int t,p,f,cs,cw,s,w;

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	while(t--)
	{
		p=read();f=read();
		cs=read();cw=read();
		s=read();w=read();
		if(s>w)
		{
			swap(s,w);
			swap(cs,cw);
		}
		int ans=0;
		for(int i=0;i*s<=p&&i<=cs;++i)
		{
			int get_1_s=i;
			int get_1_w=min(cw,(p-get_1_s*s)/w);
			int get_2_s=min(cs-get_1_s,f/s);
			int get_2_w=min(cw-get_1_w,(f-get_2_s*s)/w);
			ans=max(ans,get_1_s+get_1_w+get_2_s+get_2_w);
		}
		for(int i=0;i*s<=f&&i<=cs;++i)
		{
			int get_2_s=i;
			int get_2_w=min(cw,(f-get_2_s*s)/w);
			int get_1_s=min(cs-get_2_s,p/s);
			int get_1_w=min(cw-get_2_w,(p-get_1_s*s)/w);
			ans=max(ans,get_1_s+get_1_w+get_2_s+get_2_w);
		}
		printf("%lld\n",ans);
	}
	return 0;
}