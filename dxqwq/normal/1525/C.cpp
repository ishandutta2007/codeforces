// Problem: C. Robot Collisions
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
struct node
{
	int v;
	char s;
	int id;
}a[1000003],a0[1000003],a1[1000003],tl[1000003],tr[1000003];
bool cmp(node a,node b){return a.v<b.v;};
int ans[1000003];
int lc=0,rc=0;
void solve(node a[],int n,int r)
{
	lc=0,rc=0;
	stack<int> s;
	for(int i=1; i<=n; ++i)
	{
		if(a[i].s=='L') 
		{
			if(!s.empty()) 
			{
				int X=s.top();
				int dis=(a[i].v-a[X].v)/2;
				ans[a[X].id]=ans[a[i].id]=dis;
				s.pop();
			}
			else
			{
				tl[++lc]=a[i];
			}
		}
		else
		{
			s.push(i);
		}
	}
	while(!s.empty())
	{
		tr[++rc]=a[s.top()];
		s.pop();
	}
	for(int i=1; i+1<=lc; i+=2)
	{
		ans[tl[i].id]=ans[tl[i+1].id]=(tl[i].v+tl[i+1].v)/2;
	}
	for(int i=1; i+1<=rc; i+=2)
	{
		ans[tr[i].id]=ans[tr[i+1].id]=(r-tr[i].v+r-tr[i+1].v)/2;
	}
	if((lc&1)&&(rc&1))
	{
		ans[tl[lc].id]=ans[tr[rc].id]=(r+(r-tr[rc].v)+tl[lc].v)/2;
	}
	return ;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		int r=read();
		for(int i=1; i<=n; ++i) a[i].v=read(),a[i].id=i,ans[i]=-1;
		for(int i=1; i<=n; ++i)
		{
			a[i].s=getchar();
			while(!isupper(a[i].s)) a[i].s=getchar();
		}
		sort(a+1,a+n+1,cmp);
		int n0=0,n1=0;
		for(int i=1; i<=n; ++i) if(a[i].v%2==0)
		{
			a0[++n0]=a[i];
		}
		else a1[++n1]=a[i];
		solve(a0,n0,r);
		solve(a1,n1,r);
		for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}