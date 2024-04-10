#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	ddd*=xxx;
}
int n,k,t,ans,len,e[2][3];
string s[3],a;
char l[4]="RGB";
signed main()
{
	rd(t);
	while(t>0)
	{
		--t;
		ans=500000;
		rd(n);
		rd(k);
		for(int i=0;i<3;++i)
		{
			s[i].resize(k);
			for(int j=0;j<k;++j)
			{
				s[i][j]=l[(i+j)%3];
			}
		}
		cin>>a;
		len=a.length();
		fill(e[(k-1)&1],e[(k-1)&1]+3,0);
		for(int i=0;i<k;++i)
		{
			for(int j=0;j<3;++j)
			{
				if(a[i]!=s[j][i])
				{
					++e[(k-1)&1][j];
				}
			}
		}
		for(int i=0;i<3;++i)
		{
			ans=min(e[(k-1)&1][i],ans);
		}
		for(int i=k;i<len;++i)
		{
			for(int j=3;j<6;++j)
			{
				e[i&1][j%3]=e[(i-1)&1][(j-1)%3]-(a[i-k]!=s[(j-1)%3][0])+(a[i]!=s[j%3][k-1]);
				ans=min(e[i&1][j%3],ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}