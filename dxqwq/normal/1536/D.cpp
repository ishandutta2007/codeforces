// Problem: D. Omkar and Medians
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int a[2000003],b[1000003];
int nxt[2000003],lst[2000003];
void del(int x)
{
	nxt[lst[x]]=nxt[x];
	lst[nxt[x]]=lst[x];
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		int m=n*2-1;
		for(int i=1; i<=n; ++i) b[i]=read();
		bool f=1;
		set<int> s;
		s.insert(b[1]);
		for(int i=2; i<=n; ++i)
		{
			s.insert(b[i]);
			auto x=s.find(b[i-1]);
			auto y=s.find(b[i]);
			if(x==y) continue;
			if(b[i-1]<b[i])
			{
				++x;
			}
			else ++y;
			if(x==y) continue;
			f=0;
			break;
		}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}