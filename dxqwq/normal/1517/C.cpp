// Problem: C. Fillomino 2
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/C
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
int ans[503][503];
int a[503],p[503];
struct cmp
{
	bool operator()(const int &A,const int &B)
	const
	{
		return p[A]<p[B];
	}
};
set<int,cmp> s;
signed main()
{
    int n=read();
    for(int i=1; i<=n; ++i) 
    a[i]=read(),p[a[i]]=i,ans[i][i]=a[i];
    for(int i=n; i>1; --i)
    {
    	s.insert(i);
    	auto it=s.begin();
    	for(int X=i,Y=1; X<=n; ++X,++Y,++it) ans[X][Y]=*it;
    	
    }
    for(int i=1; i<=n; ++i,puts(""))
    for(int j=1; j<=i; ++j) printf("%lld ",ans[i][j]);
	return 0;
}