#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 300000
ll va[MN+5],vb[MN+5];
int van,vbn;
int main()
{
	int a,b,c,m,x,mx=0,aa,bb,i;ll mn=0;char s[10];
	a=read();b=read();c=read();
	for(m=read();m--;)
	{
		x=read();scanf("%s",s);
		(s[0]=='U'?va[++van]:vb[++vbn])=x;
	}
	sort(va+1,va+van+1);sort(vb+1,vb+vbn+1);
	for(i=1;i<=van;++i)va[i]+=va[i-1];
	for(i=1;i<=vbn;++i)vb[i]+=vb[i-1];
	for(i=0;i<=c;++i)if((aa=min(i+a,van))+(bb=min(c-i+b,vbn))>=mx)
	{
		if(aa+bb>mx)mn=(1LL<<60);
		mx=aa+bb;
		if(va[aa]+vb[bb]<mn)mn=va[aa]+vb[bb];
	}
	cout<<mx<<' '<<mn;
}