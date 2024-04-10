// Problem: D. Fishes
// Contest: Codeforces - Codeforces Round #456 (Div. 2)
// URL: https://codeforces.com/contest/912/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define qaq(x,y) vis[make_pair(x,y)]=1,q.push(make_pair(x,y))
#define qwq(x,y) vis[make_pair(y,x)]=1,q.push(make_pair(y,x))
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
map<pair<int,int>,bool> vis;
int n=read(),m=read(),r=read(),k=read();
int val(pair<int,int> x)
{
	int i=x.first,j=x.second;
 		int u=min(n-r+1,i)-max(1ll,i-r+1)+1;
 		int v=min(m-r+1,j)-max(1ll,j-r+1)+1;
 		return u*v;
}
bool valid(int x,int y)
{
	if(vis[make_pair(x,y)]) return 0;
	if(1<=x&&x<=n&&1<=y&&y<=m) return 1;
	return 0;
}
struct cmp
{
	bool operator()(pair<int,int> x,pair<int,int> y)
	{
		return val(x)<val(y);
	}
};
signed main()
{
 	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> q;
 	int ans=0;
 	if(n&1ll) if(m&1ll) qaq((n+1)>>1,(m+1)>>1);
 	else qaq((n+1)>>1,m>>1),qaq((n+1)>>1,(m>>1)+1);
 	else if(m&1ll) qwq((m+1)>>1,n>>1),qwq((m+1)>>1,(n>>1)+1);
 	else qaq(n>>1,m>>1),qaq(n>>1,(m>>1)+1),qwq(m>>1,(n>>1)+1),qwq((m>>1)+1,(n>>1)+1);
 	for(int i=1; i<=k; i++)
 	{
 		pair<int,int> p=q.top();q.pop();
 		ans+=val(p);
 		int x=p.first,y=p.second;
 		++x;
 		if(valid(x,y)) qaq(x,y); 
 		--x;
 		--x;if(valid(x,y)) qaq(x,y); 
 		++x;
 		++y;if(valid(x,y)) qaq(x,y); 
 		--y;
 		--y;if(valid(x,y)) qaq(x,y); 
 		++y;
 	}
 	int tot=(n-r+1)*(m-r+1);
 	printf("%.10lf\n",1.0*ans/tot);
	return 0;
}