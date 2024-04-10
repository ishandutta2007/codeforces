// Problem: F. Phoenix and Earthquake
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fa[1000003];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
map<int,int> mp[1000003];
bool vis[1000003];
bool VIS[1000003];
void merge(int x,int y)
{
	if(mp[x].size()>mp[y].size())
	{
		for(auto i:mp[y]) if(!vis[i.second]) mp[x][i.first]=i.second; 
	}
	else
	{
		for(auto i:mp[x]) if(!vis[i.second]) mp[y][i.first]=i.second; 
		swap(mp[x],mp[y]);
	}
	fa[y]=x;
}
int ANS[1000003],CNT;
void print()
{
	for(int i=1; i<=CNT; ++i) printf("%lld\n",ANS[i]);
	return;
}
int a[1000003];
#define mkp make_pair
signed main()
{
    int n=read(),m=read(),x=read();
    priority_queue<pair<int,int> > q;
    for(int i=1; i<=n; ++i) a[i]=read(),fa[i]=i,
    q.push(mkp(a[i],i));
    for(int i=1,u,v; i<=m; ++i) 
    u=read(),v=read(),mp[u][v]=i,mp[v][u]=i;
    while(1)
    {
    	pair<int,int> A=q.top();
    	q.pop();
    	if(find(A.second)!=A.second) continue;
    	int id=A.second;
    	vector<int> er;
    	for(auto i:mp[id])
    	{
    		if(vis[i.second]) 
    		{
    			er.push_back(i.first);
    			continue;
    		}
    		int C=find(i.first);
    		if(id==C)
    		{
    			er.push_back(i.first);
    			continue;
    		}
    		if(a[C]+a[id]<x) puts("NO"),exit(0);
    		else
    		{
    			vis[i.second]=1;
    			VIS[C]=1;
    			ANS[++CNT]=i.second;
    			a[id]+=a[C]-x;
    			merge(id,C);
    			mp[id].erase(i.first);
    			break;
    		}
    	}
    	for(auto i:er) mp[id].erase(i);
    	A.first=a[id];
    	q.push(A);
    	if(CNT>=n-1) break;
    }
    puts("YES"),print();
	return 0;
}