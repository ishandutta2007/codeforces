// Problem: A. Balanced Bitstring
// Contest: Codeforces - Codeforces Round #668 (Div. 1)
// URL: https://codeforces.com/contest/1404/problem/A
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
char s[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		scanf("%s",s+1);
		bool f=1;
		int X=0,Y=0;
		for(int i=1; i<=m; ++i)
		{
			bool x=0,y=0;
			for(int j=i; j<=n; j+=m) if(s[j]=='1') x=1;
			else if(s[j]=='0') y=1;
			if(x&&y) f=0;
			else if(x) ++X;
			else if(y) ++Y;
		}	
		if(X>(m/2)) f=0;
		if(Y>(m/2)) f=0;
		if(f) puts("YES");
		else puts("NO");
	}
    return 0;
}