#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,a[200001],num[10],ans,len;
char s[200001];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s);
		len=strlen(s);
		memset(num,0,sizeof(num));
		for(register int i=0;i<len;++i)
		{
			a[i+1]=s[i]-'0';
			++num[a[i+1]];
		}
		ans=len;
		for(register int i=0;i<=9;++i)
			ans=min(ans,len-num[i]);
		for(register int i=0;i<=9;++i)
		{
			for(register int j=0;j<=9;++j)
			{
				if(i==j || (len-2*min(num[i],num[j])>ans))
					continue;
				int maxlen=0,last=1;
				for(register int k=1;k<=len;++k)
					if(last)
					{
						if(a[k]==i)
							++maxlen,last=0;
					}
					else
					{
						if(a[k]==j)
							++maxlen,last=1;
					}
				if(last==0)
					--maxlen;
				ans=min(ans,len-maxlen);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}