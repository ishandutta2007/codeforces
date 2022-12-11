#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MN 100000
string s[MN+5];
int cnt,p[MN+5],z[MN+5],u[MN*5+5];
queue<int> a,b,c,d,A,B,C;
vector< pair<int,int> > v;
int main()
{
	int n,e=0,i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		cin>>s[i];scanf("%d",&p[i]);e+=p[i];
		for(x=j=0;s[i][j];++j)
			if(s[i][j]<'0'||s[i][j]>'9'||(!x&&s[i][j]=='0'))break;
			else x=x*10+s[i][j]-'0';
		z[i]=s[i][j]?x=MN*5+1:x;
		if(x<=MN*5)u[x]=1;
	}
	for(i=1;i<=n;++i)
	{
		if(p[i])
		{
			if(z[i]>e&&z[i]<=n)a.push(z[i]);
			if(z[i]<1||z[i]>n)b.push(-i);
		}
		else
		{
			if(z[i]&&z[i]<=e)c.push(z[i]);
			if(z[i]<1||z[i]>n)d.push(-i); 
		}
	}
	for(i=1;i<=e;++i)if(!u[i])A.push(i);
	for(;i<=n;++i)if(!u[i])B.push(i);
	for(;i<=5*n;++i)if(!u[i])C.push(i);
	while(!a.empty()||!b.empty()||!c.empty()||!d.empty())
	{
		if(!a.empty()&&!A.empty())
		{
			v.push_back(make_pair(a.front(),A.front())); 
			B.push(a.front());a.pop();A.pop();continue;
		}
		if(!c.empty()&&!B.empty())
		{
			v.push_back(make_pair(c.front(),B.front()));
			A.push(c.front());c.pop();B.pop();continue;
		}
		if(!a.empty())
		{
			v.push_back(make_pair(c.front(),C.front()));
			A.push(c.front());d.push(C.front());c.pop();C.pop();continue;
		}
		if(!b.empty())
		{
			v.push_back(make_pair(b.front(),A.front()));
			b.pop();A.pop();continue;
		}
		if(!d.empty())
		{
			v.push_back(make_pair(d.front(),B.front()));
			d.pop();B.pop();continue;
		}
	}
	printf("%d\n",v.size());
	for(i=0;i<v.size();++i)
	{
		printf("move ");
		if(v[i].first<0)cout<<s[-v[i].first]<<' ';
		else printf("%d ",v[i].first);
		printf("%d\n",v[i].second);
	}
}