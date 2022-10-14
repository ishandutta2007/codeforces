// Problem: A. Determine Line
// Contest: Codeforces - Mail.Ru Cup 2018 Round 3
// URL: https://codeforces.com/contest/1056/problem/A
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
int a[1000003];
signed main()
{
	int n=read();
	bitset<103> ans;
	ans.set();
	for(int i=1; i<=n; ++i)
	{
		a[i]=read();
		bitset<103> bs;
		bs.reset();
		for(int j=1; j<=a[i]; ++j)
		bs[read()]=1;
		ans&=bs;
	}
	for(int i=1; i<=103; ++i)
	if(ans[i]) printf("%lld ",i);
    return 0;
}