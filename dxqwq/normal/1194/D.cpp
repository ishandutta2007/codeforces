// Problem: D. 1-2-K Game
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		if(n==0)
		{
			puts("Bob");
		}
		else
		{
			int t=m%3;
			if(t)
			{
				int A=n%3;
				if(A) puts("Alice");
				else puts("Bob");
			}
			else
			{
				int A=n%(m+1);
				if(A%3==0&&A!=m) puts("Bob");
				else puts("Alice");
			}
		}
	}
    return 0;
}