#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
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
int T,ma,mb,ans,len;
char s[200001];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		ma=mb=ans=0;
		for(int i=1;i<=len;++i)
		{
			if(s[i]=='(') ++ma;
			if(s[i]==')' && ma) --ma,++ans;
			if(s[i]=='[') ++mb;
			if(s[i]==']' && mb) --mb,++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}