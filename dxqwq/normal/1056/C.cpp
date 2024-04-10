// Problem: C. Pick Heroes
// Contest: Codeforces - Mail.Ru Cup 2018 Round 3
// URL: https://codeforces.com/contest/1056/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
bool f[1000003];
int a[1000003];
int X[1000003],Y[1000003];
int C=0;
int F[1000003];
struct cmp
{
	bool operator()(const int&x,const int&y)
	{
		return (a[x]>a[y])||(a[x]==a[y]&&x<y);
	}
};
set<int,cmp> s;
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n*2; ++i) a[i]=read();
	for(int i=1; i<=m; ++i)
	{
		int A=read(),B=read();
		X[++C]=A,Y[C]=B;
		F[A]=B,F[B]=A;
	}
	int op=read();
	if(op==1)
	{
		for(int i=1; i<=C; ++i)
		{
			if(a[X[i]]>=a[Y[i]]) 
			printf("%lld ",X[i]);
			else printf("%lld ",Y[i]);
			puts("");
			fflush(stdout);
			read();
			f[X[i]]=f[Y[i]]=1;
		}
		for(int i=1; i<=2*n; ++i)
		{
			if(!f[i]) s.insert(i);
		}
		while(!s.empty())
		{
			int A=*(s.begin());
			s.erase(s.begin());
			printf("%lld\n",A);
			fflush(stdout);
			int B=read();
			s.erase(B);
		}
	}
	else
	{
		int D=0,G=0;
		while(1)
		{
			int x=read();
			f[x]=1;
			if(F[x]) 
			{
				++G,printf("%lld\n",F[x]),f[F[x]]=1,fflush(stdout),++D;
			if(G==n) return 0;
			}
			else break;
		}
		for(int i=1; i<=C; ++i) if(!f[X[i]])
		{
			if(a[X[i]]>=a[Y[i]]) 
			printf("%lld ",X[i]);
			else printf("%lld ",Y[i]);
			puts("");
			fflush(stdout);
			++G;
			if(G==n) return 0;
			read();
			f[X[i]]=f[Y[i]]=1;
		}
		for(int i=1; i<=2*n; ++i)
		{
			if(!f[i]) s.insert(i);
		}
		while(!s.empty())
		{
			int A=*(s.begin());
			s.erase(s.begin());
			printf("%lld\n",A);
			fflush(stdout);
			if(G==n) return 0;
			if(s.empty()) break;
			int B=read();
			s.erase(B);
		}
	}
    return 0;
}