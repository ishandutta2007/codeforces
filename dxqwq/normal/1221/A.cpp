// Problem: A. 2048 Game
// Contest: Codeforces - Educational Codeforces Round 73 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1221/problem/A
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

signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		int S=0;
		for(int i=1; i<=n; ++i) 
		{
			int A=read();
			if(A<=2048) S+=A;
		}
		if(S>=2048) puts("YES");
		else puts("NO");
	}
    return 0;
}