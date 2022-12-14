#include<bits/stdc++.h>
#define ll long long
#define mes(x,y) memset(x,y,sizeof(x))
#define mpy(x,y) memcpy(x,y,sizeof(x))
#define Maxn 200000
#define INF 2147483647
using namespace std;
inline ll read()
{
	ll f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
ll n,m,d,a[Maxn+1],tmp,ans;
set<ll>s;
map<ll,ll>mapp;
int main()
{
	n=read();m=read();d=read();
	for(register int i=1;i<=n;i++)
	tmp=read(),mapp[tmp]=i,s.insert(tmp);
	s.insert(INF);
	tmp=ans=1;
	for(register int i=1;i<=n;i++)
	{
		tmp=*s.lower_bound(tmp);
		if(tmp==INF) ans++,tmp=1,i--;	
		else a[mapp[tmp]]=ans,s.erase(tmp),tmp+=d+1;
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;i++)
	printf("%I64d ",a[i]);
	return 0;
}