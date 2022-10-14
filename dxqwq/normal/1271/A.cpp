// Problem: A. Suits
// Contest: Codeforces - Codeforces Round #608 (Div. 2)
// URL: https://codeforces.com/contest/1271/problem/A
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
	int a=read(),b=read(),c=read(),d=read();
	int A=a,B=min(b,c);
	int E=read(),F=read();
	if(E<F)
	{
		int G=min(B,d);
		d-=G;
		int K=min(A,d);
		printf("%lld\n",G*F+K*E);
	}
	else
	{
		int G=min(A,d);
		d-=G;
		int K=min(B,d);
		printf("%lld\n",G*E+K*F);
	}
    return 0;
}