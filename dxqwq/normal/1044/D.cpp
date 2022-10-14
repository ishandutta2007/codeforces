// Problem: G. [2400] Problem G
// Contest: Codeforces - Lockout Round 6
// URL: https://codeforces.com/gym/323366/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
map<int,int> mp;
int cnt=0;
int fa[1000003],d[1000003];
int find(int x)
{
	if(fa[x]==x) return x;
	int X=fa[x];
	fa[x]=find(fa[x]);
	d[x]=d[x]^d[X];
	return fa[x];
}
signed main()
{
	for(int i=1; i<=1000000; i++) fa[i]=i;
	int lst=0;
	for(int T=read();T--;)
	{

		int op=read(),l=read(),r=read();
		if(op==1)
		{
			int x=read();
			l^=lst,r^=lst,x^=lst;
			if(r<l) swap(l,r);
			--l; 
			if(!mp[l]) mp[l]=++cnt;
			if(!mp[r]) mp[r]=++cnt;
			int ll=find(mp[l]),rr=find(mp[r]);
			x^=d[mp[l]]^d[ll]^d[mp[r]]^d[rr];
			if(ll!=rr)
			{
				fa[rr]=ll;
				d[rr]=x;
			}
		}
		else
		{
			l^=lst,r^=lst;
			if(r<l) swap(l,r);
			--l;
			if(!mp[l]||!mp[r]) 
			{
				puts("-1");lst=1;
				continue;
			}
			l=mp[l],r=mp[r];
			int ll=find(l),rr=find(r);
			if(ll==rr)
			{
				lst=d[l]^d[r];
				printf("%lld\n",d[l]^d[r]);
			}
			else
			{
				puts("-1");lst=1;
			}
		}
	}
    return 0;
}