// Problem: B. Prinzessin der Verurteilung
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/B
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
char s[1000003];
map<int,int> mp;
int f(int l,int r)
{
	int rr=0;
	for(int i=l; i<=r; ++i) rr*=27,rr+=s[i]-'a'+1;
	return rr;
}
int print(int x)
{
	stack<char> s;
	while(x) 
	if(x%27==0) return 1;
	else s.push('a'+x%27-1),x/=27;
	while(!s.empty()) putchar(s.top()),s.pop();
	puts(""); 
	return 0;
}
signed main()
{
	for(int T=read();T--;)
	{
		mp.clear();
		int n=read();
		scanf("%s",s+1);
		for(int i=1; i<=n; ++i) 
		for(int j=i; j<=i+4&&j<=n; ++j) mp[f(i,j)]=1;
		bool f=1;
		for(int i=1; f; ++i) if(mp[i]==0)
		f=print(i);
	}
	return 0;
}