#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MN=2e5;
char s[MN+5];
priority_queue<int> mx[3],mxd[3];
priority_queue<int,vector<int>,greater<int> > mn[3],mnd[3];
int u[256],a[3][MN+5];
void add(int*a,int x,int z){for(;x<=MN;x+=x&-x)a[x]+=z;}
int sum(int*a,int x){int r=0;for(;x;x-=x&-x)r+=a[x];return r;}
int cal()
{
	int r=0,i;
	for(i=0;i<3;++i)
	{
		if(!mx[(i+2)%3].size())r+=sum(a[i],MN);
		else if(mx[(i+1)%3].size())
		{
			int l1=mn[(i+1)%3].top(),l2=mn[(i+2)%3].top(),r1=mx[(i+1)%3].top(),r2=mx[(i+2)%3].top();
			r+=sum(a[i],min(r1,l2))+sum(a[i],MN)-sum(a[i],max(l1,r2));
			if(max(l1,l2)<min(r1,r2))r+=sum(a[i],min(r1,r2))-sum(a[i],max(l1,l2));
		}
	}
	return r;
}
int main()
{
	u['R']=0;u['S']=1;u['P']=2;
	int n,q,i;char o[5];
	n=read();q=read();
	scanf("%s",s+1);
	for(i=1;i<=n;++i)
	{
		s[i]=u[s[i]];
		add(a[s[i]],i,1);
		mx[s[i]].push(i);
		mn[s[i]].push(i);
	}
	printf("%d\n",cal());
	while(q--)
	{
		i=read();scanf("%s",o);o[0]=u[o[0]];
		add(a[s[i]],i,-1);
		mxd[s[i]].push(i);while(mxd[s[i]].size()&&mx[s[i]].top()==mxd[s[i]].top())mx[s[i]].pop(),mxd[s[i]].pop();
		mnd[s[i]].push(i);while(mnd[s[i]].size()&&mn[s[i]].top()==mnd[s[i]].top())mn[s[i]].pop(),mnd[s[i]].pop();
		s[i]=o[0];
		add(a[s[i]],i,1);
		mx[s[i]].push(i);
		mn[s[i]].push(i);
		printf("%d\n",cal());
	}
}