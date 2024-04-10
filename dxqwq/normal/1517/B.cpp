// Problem: B. Morning Jogging
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
pair<int,pair<int,int> > a[10003];
bool f[503][503];
bool F[503];
int ans[503][503];
int b[503][503];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read(),m=read();
    	int c=0;
    	for(int i=1; i<=n; ++i) 
    	for(int j=1; j<=m; ++j)
    	a[++c].first=read(),
    	a[c].second=make_pair(i,j),
    	f[i][j]=0,
    	b[i][j]=a[c].first;
    	sort(a+1,a+c+1);
    	for(int i=1; i<=m; ++i) 
    	f[a[i].second.first]
		[a[i].second.second]=1;
		int cur=0;
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=500; ++j) F[j]=0;
			for(int j=1;j<=m; ++j) if(f[i][j])
			ans[i][++cur]=b[i][j],F[cur]=1;
			int A=1;
			
			for(int j=1; j<=m; ++j) if(!f[i][j])
			{
				while(F[A]) ++A;
				ans[i][A]=b[i][j];
				++A;
			}
		}
		for(int i=1; i<=n; ++i,puts(""))
		for(int j=1; j<=m; ++j) printf("%lld ",ans[i][j]);
    }
	return 0;
}