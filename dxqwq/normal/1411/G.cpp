// Problem: G. No Game No Life
// Contest: Codeforces - Technocup 2021 - Elimination Round 3
// URL: https://codeforces.com/problemset/problem/1411/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
vector<int> e[100003];
int ans[1003],deg[100003];
unordered_set<int> s[100003];
int sg[100003];
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int m[1003][1003];
void work(int sz){
	int d;
	for(int i=1; i<=sz; ++i) 
    {
        for(int j=i+1; j<=sz; ++j) if(m[j][i]>m[i][i]) for(int k=i; k<=sz+1; ++k) swap(m[i][k],m[j][k]);
		if(m[i][i]) for(int j=i+1; j<=sz; ++j)
		{
			d=(p-m[j][i]*qp(m[i][i],p-2)%p)%p;
			for(int k=i; k<=sz+1; k++) (m[j][k]+=d*m[i][k]%p)%=p;
		}
	}
	ans[sz]=m[sz][sz+1]*qp(m[sz][sz],p-2)%p;
	for(int i=sz-1; i>=1; i--)
    {
		for(int j=sz; j>=i; j--) m[i][sz+1]=(p+m[i][sz+1]-m[i][j]*ans[j]%p)%p;
		ans[i]=m[i][sz+1]*qp(m[i][i],p-2)%p;
    }
    return ;
}
signed main()
{
	int n=read();
	for(int i=1,u,v,m=read(); i<=m; ++i) 
		u=read(),v=read(),e[v].push_back(u),++deg[u];
	queue<int> q;
	for(int i=1; i<=n; ++i) if(!deg[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		while(s[x].find(sg[x])!=s[x].end()) ++sg[x];
		for(int i:e[x])
		{
			--deg[i],s[i].insert(sg[x]);
			if(!deg[i]) q.push(i);
		}	
	}
	int C=512;
	int G=qp(n+1,p-2);
	//return 0;
	for(int i=1; i<C; ++i)
	{
		for(int j=1; j<=n; ++j) (m[i][(i^sg[j])+1]+=G)%=p;
		(m[i][i+1]+=p-1)%=p;
	}
	for(int i=1; i<=C+1; ++i) m[C][i]=1;
	//for(int i=1; i<=C; ++i,puts("")) for(int j=1; j<=C+1; ++j) printf("%lld ",m[i][j]);
	//return 0; 
	work(C);
	printf("%lld\n",(p+1-ans[1])%p);
    return 0;
}