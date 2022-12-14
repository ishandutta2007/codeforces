#include<bits/stdc++.h>
using namespace std;
#define re register long long
#define db double
#define rd register db
#define ak *
#define inf 1e18
char qwq;
long long ans,n,s[100005],fa[100005];
inline long long read()
{
    re yz=0,ioi=1;qwq=getchar();
    while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:ioi,qwq=getchar();
    while(isdigit(qwq)) yz=(yz<<3)+(yz<<1)+(qwq^48),qwq=getchar();
    return yz ak ioi;
}
int main()
{
	n=read();
	for(re i=2;i<=n;i++) fa[i]=read();
	for(re i=1;i<=n;i++) 
	{
		s[i]=read();
		if(s[i]==-1) s[i]=inf;
		s[fa[i]]=min(s[i],s[fa[i]]);
	}
	for(re i=1;i<=n;i++)
	{
		if(s[i]==inf) s[i]=s[fa[i]];
		else if(s[fa[i]]>s[i]) puts("-1"),exit(0);
		ans+=s[i]-s[fa[i]];
	}
	cout<<ans;
}