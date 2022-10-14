// Problem: B. Fibonacci Strings
// Contest: Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		priority_queue<pair<int,int>> q;
		int s=0;
		for(int i=1,x; i<=n; ++i) 
			x=read(),s+=x,q.push(make_pair(x,i));
		vector<int> v;
		if(s==1){puts("YES");continue;}
		for(int a=0,b=1,c=1; s>0; v.push_back(b),s-=b,
		c=a+b,a=b,b=c);
		if(s<0){puts("NO");continue;}
		reverse(v.begin(),v.end());
		bool flg=1;
		int lst=-1;
		for(int i:v)
		{
			int x=q.top().first;
			int y=q.top().second;
			if(x>=i)
			{
				if(y==lst)
				{
					auto it=q.top();
					q.pop();
					if(q.empty())
					{
						flg=0;break;
					}
					else x=q.top().first,
						y=q.top().second;
					if(x>=i)
					{
						q.pop(),q.push(it);
					}
					else
					{
						flg=0;break;
					}
				}
				else q.pop();
				lst=y;
				if(x-i>0)
					q.push(make_pair(x-i,y));
			}
			else
			{
				flg=0;break;
			}
		}
		if(flg) puts("YES"); else puts("NO");
	}
	return 0;
}