// Problem: CF527E Data Center Drama
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF527E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int t[2000003],cnt;
bool vis[2000003];
int st[1000003];
vector<pair<int,int> > e[1000003];
vector<pair<int,int> > ans;
vector<int> A;
bool g=1;
inline void dfs(int x){
    for(int i=st[x];i<e[x].size();i=max(i+1,st[x])){
        int t=e[x][i].first;
        if(!vis[e[x][i].second]){
            vis[e[x][i].second]=1;
            st[x]=i+1;
            g^=1;
            dfs(t);
        }
    }
    A.push_back(x);
    return ;
}
signed main()
{
	int n=read(),m=read();
	cnt=m;
	for(int i=1,u,v; i<=m; ++i) 
		u=read(),v=read(),e[u].push_back(make_pair(v,i)),e[v].push_back(make_pair(u,i));
	vector<int> tt;
	for(int i=1; i<=n; ++i) if(((int)e[i].size())&1) tt.push_back(i);
	int N=tt.size();
	assert((N+1)&1);
	for(int i=0,u,v; i+1<N; i+=2) 
		//printf("%d\n",tt[i]^tt[i+1]),
		u=tt[i],v=tt[i+1],++cnt,e[u].push_back(make_pair(v,cnt)),e[v].push_back(make_pair(u,cnt));
	dfs(1);
	int L=(int)A.size();
	for(int i=0; i+1<L; ++i) if(i&1) ans.push_back(make_pair(A[i+1],A[i]));
	else ans.push_back(make_pair(A[i],A[i+1]));
	if(cnt&1) ans.push_back(make_pair(1,1));
	printf("%d\n",(int)ans.size());
	for(auto i:ans) printf("%d %d\n",i.first,i.second);
	return 0;
}