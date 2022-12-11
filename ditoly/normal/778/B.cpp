#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 5000
#define MM 1000
map<string,int> mp;
int n,a[MN+5][MM+5],cnt;
int t[MN+5],ta[MN+5],tb[MN+5];
int aa[MM+5],bb[MM+5];
int f[MN+5];
int check(int p,int k)
{
	int i,s=0;
	for(i=1;i<=n;++i)
	{
		if(!t[i])f[i]=a[i][p];
		if(t[i]==1)f[i]=(ta[i]?f[ta[i]]:k)&(tb[i]?f[tb[i]]:k);
		if(t[i]==2)f[i]=(ta[i]?f[ta[i]]:k)|(tb[i]?f[tb[i]]:k);
		if(t[i]==3)f[i]=(ta[i]?f[ta[i]]:k)^(tb[i]?f[tb[i]]:k);
		s+=f[i];
	}
	return s;
}
int main()
{
	int m,i,j,x,y;string s;
	n=read();m=read();
	for(i=1;i<=n;++i)
	{
		cin>>s;mp[s]=++cnt;cin>>s;
		cin>>s;
		if(s[0]=='0'||s[0]=='1')
		{
			for(j=0;j<m;++j)a[i][j]=s[j]-'0';
			continue;
		}
		ta[i]=s[0]=='?'?0:mp[s];
		cin>>s;
		if(s[0]=='A')t[i]=1;
		if(s[0]=='O')t[i]=2;
		if(s[0]=='X')t[i]=3;
		cin>>s;
		tb[i]=s[0]=='?'?0:mp[s];
	}
	for(i=0;i<m;++i)
	{
		x=check(i,0);y=check(i,1);
		aa[i]=y<x;bb[i]=y>x;
	}
	for(i=0;i<m;++i)printf("%d",aa[i]);puts("");
	for(i=0;i<m;++i)printf("%d",bb[i]);
}