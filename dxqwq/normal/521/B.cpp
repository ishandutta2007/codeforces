// Problem: B. Cubes
// Contest: Codeforces - Codeforces Round #295 (Div. 1)
// URL: https://codeforces.com/contest/521/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int mod=1e9+9;
inline int qpow(int s,int y,int ret=1)
{
	for(;y;y>>=1,s=1ll*s*s%mod) if(y&1) ret=1ll*ret*s%mod; 
	return ret;
}
map<pair<int,int>,int> mp;
set<int> s;
int f[100003],x[100003],y[100003];
int locked[100003];
int recalc(int i)
{
	f[i]=
	(mp[make_pair(x[i]-1,y[i]-1)]>0)+
	(mp[make_pair(x[i],y[i]-1)]>0)+
	(mp[make_pair(x[i]+1,y[i]-1)]>0);
		if(f[i]==1)
		{
			if(mp[make_pair(x[i]-1,y[i]-1)]) 
			{
				int X=mp[make_pair(x[i]-1,y[i]-1)];
				locked[X]++;
				if(s.find(X)!=s.end()) s.erase(s.find(X));
			}
			if(mp[make_pair(x[i],y[i]-1)]) 
			{
				int X=mp[make_pair(x[i],y[i]-1)];
				locked[X]++;
				if(s.find(X)!=s.end()) s.erase(s.find(X));
			}
			if(mp[make_pair(x[i]+1,y[i]-1)]) 
			{
				int X=mp[make_pair(x[i]+1,y[i]-1)];
				locked[X]++;
				if(s.find(X)!=s.end()) s.erase(s.find(X));
			}
			
		}
}
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) x[i]=read(),y[i]=read(),mp[make_pair(x[i],y[i])]=i;
    for(int i=1; i<=n; i++) if(y[i])
    {
    	f[i]=(mp[make_pair(x[i]-1,y[i]-1)]>0)+(mp[make_pair(x[i],y[i]-1)]>0)+(mp[make_pair(x[i]+1,y[i]-1)]>0);
		if(f[i]==1)
		{
			if(mp[make_pair(x[i]-1,y[i]-1)]) locked[mp[make_pair(x[i]-1,y[i]-1)]]++;
			if(mp[make_pair(x[i],y[i]-1)]) locked[mp[make_pair(x[i],y[i]-1)]]++;
			if(mp[make_pair(x[i]+1,y[i]-1)]) locked[mp[make_pair(x[i]+1,y[i]-1)]]++;
		}
    }
    for(int i=1; i<=n; i++) if(!locked[i]) s.insert(i);
    int ans=0;
    for(int i=n-1,ss=1; i>=0; i--,ss^=1)
    {
    	int t;
    	if(ss) t=*(s.rbegin()),s.erase(t);
    	else t=*(s.begin()),s.erase(t);
    	//printf("%d\n",t-1);
    	(ans+=(t-1)*qpow(n,i)%mod)%=mod;
    	mp[make_pair(x[t],y[t])]=0;
    	if(f[t]==1)
    	{
			if(mp[make_pair(x[t]-1,y[t]-1)]) 
			{
				locked[mp[make_pair(x[t]-1,y[t]-1)]]--;
				if(locked[mp[make_pair(x[t]-1,y[t]-1)]]==0)
				s.insert(mp[make_pair(x[t]-1,y[t]-1)]);
			}
			if(mp[make_pair(x[t],y[t]-1)]) 
			{
				locked[mp[make_pair(x[t],y[t]-1)]]--;
				if(locked[mp[make_pair(x[t],y[t]-1)]]==0)
				s.insert(mp[make_pair(x[t],y[t]-1)]);
			}
			if(mp[make_pair(x[t]+1,y[t]-1)]) 
			{
				locked[mp[make_pair(x[t]+1,y[t]-1)]]--;
				if(locked[mp[make_pair(x[t]+1,y[t]-1)]]==0)
				s.insert(mp[make_pair(x[t]+1,y[t]-1)]);
			}
    	}
		if(mp[make_pair(x[t]-1,y[t]+1)]) recalc(mp[make_pair(x[t]-1,y[t]+1)]);
		if(mp[make_pair(x[t],y[t]+1)]) recalc(mp[make_pair(x[t],y[t]+1)]);
		if(mp[make_pair(x[t]+1,y[t]+1)]) recalc(mp[make_pair(x[t]+1,y[t]+1)]);
    }
    printf("%lld\n",ans);
	return 0;
}