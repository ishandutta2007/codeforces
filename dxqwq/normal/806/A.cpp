// Problem: A. Success Rate
// Contest: Codeforces - Codeforces Round #412 (rated, Div. 1, based on VK Cup 2017 Round 3)
// URL: https://codeforces.com/contest/806/problem/A
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
		int n=read(),m=read(),x=read(),y=read();
		if(x==0)
		{
			if(n==0)
			{
				puts("0");
			}
			else puts("-1");
		}
		else if(x==y)
		{
			if(n==m) puts("0");
			else puts("-1");
		}
		else 
		{
			int g=__gcd(x,y);
			x/=g,y/=g;
			int t=(n-1)/x+1;
			int t1=(m-1)/y+1;
			//50 100
			//1  3
			//50 150
			int t3=(m-n-1)/(y-x)+1;
			int t2=max(t,t1);
			t2=max(t3,t2);
			y*=t2;
			printf("%lld\n",y-m);
		}
	}
    return 0;
}