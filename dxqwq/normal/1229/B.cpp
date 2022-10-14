#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[100003];
map<long long,int> mp[100003]; 
long long x[100003],ans,n,a,b;
void dfs(int v,int p) 
{
    ++mp[v][x[v]];
    ans+=x[v];
    for(map<long long,int>::iterator qwq=mp[p].begin(); qwq!=mp[p].end(); qwq++) 
	{
        pair<long long,int> t=(*qwq);
		long long cur=__gcd(x[v],t.first);
        ans=(ans+cur*t.second%1000000007LL)%1000000007LL;
        mp[v][cur]+=t.second;
    }
    int sz=g[v].size();
    for(int i=0; i<sz; i++) if(p!=g[v][i]) dfs(g[v][i],v);
}
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main() 
{
    n=read();
    for(int i=1; i<=n; ++i) x[i]=read();
    for(int i=0; i<n-1; ++i) 
	{
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}