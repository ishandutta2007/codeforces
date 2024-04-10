#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<iostream>
#define int long long
#define INF 0x3fffffffffffffff
#define it :: iterator
using namespace std;
inline int rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-'&&tmp!=EOF)
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
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
	return ddd*=xxx;
}
inline char rd(char &ddd)
{
	char tmp=getchar();
	while(tmp==' '||tmp=='\n')
	{
		tmp=getchar();
	}
	if(tmp==EOF)
	{
		return EOF;
	}
	return ddd=tmp;
}
inline int max(const int &A,const int &B)
{
	return A<B?B:A;
}
inline int min(const int &A,const int &B)
{
	return A<B?A:B;
}
int n,m,q,ans[100001][2];
vector <int> a;
vector <int> it b;
signed main()
{
	rd(n);
	rd(m);
	for(int i=1;i<=n;++i)
	{
		rd(q);
		a.push_back(q);
	}
	for(int i=1;i<=n;++i)
	{
		b=a.begin();
		ans[i][0]=*b;
		ans[i][1]=*(b+1);
		a.erase(b);
		b=a.begin();
		if(ans[i][0]>ans[i][1])
		{
			*b=ans[i][0];
			a.push_back(ans[i][1]);
		}
		else
		{
			*b=ans[i][1];
			a.push_back(ans[i][0]);
		}
	}
	b=a.begin();
	for(int i=1;i<=m;++i)
	{
		rd(q);
		if(q<=n)
		{
			cout<<ans[q][0]<<' '<<ans[q][1]<<endl;
		}
		else
		{
			cout<<*b<<' '<<*(b+1+(q-n-1)%(n-1))<<endl;
		}
	}
	return 0;
}