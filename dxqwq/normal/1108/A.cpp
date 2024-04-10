// Problem: A. Two distinct points
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/A
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
		int A=read(),B=read();
		int C=read(),D=read();
		printf("%lld ",A);
		if(C<A) printf("%lld",C);
		else printf("%lld",D);
		puts("");
	}
    return 0;
}