// Problem: F. Relatively Prime Powers
// Contest: Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1036/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
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
__int128 qwq(__int128 x,int y)
{
	__int128 ans=1;
	for(int i=1; i<=y; i++) ans*=x;
	return ans;
}
int c[10003],isp[10003];
signed main()
{
	for(int i=2; i<=64; i++)
	{
		isp[i]=1;
		for(int j=2; j<i; j++)
		{
			if(i%j==0) isp[i]=0;
		}
		for(int j=2; j<=i; ++j)
		{
			if(i%j==0&&isp[j]) ++c[i];
		}
		for(int j=2; j<i; ++j)
		{
			if(i%(j*j)==0) c[i]=-1;
		}
	}
 	for(int T=read();T--;)
 	{
 		int n=read(),ans=0;
 		__int128 lovetino=n;
	 	for(int i=2; i<=38; i++)
	 	{
	 		int x=pow(1.0L*n,1.0L/i);
	 		while(qwq(x,i)>lovetino) --x;
	 		while(qwq(x+1,i)<=lovetino) ++x;
	 		--x;
	 		int cnt=c[i];if(c[i]!=-1) 
	 		if(cnt&1) ans+=x; else ans-=x;
	 	}
	 	for(int i=39; i<=63; i++)
	 	{
	 		int x=0;
	 		if((1ll<<i)<=n) x=1; else break;
	 		int cnt=c[i];
	 		if(c[i]!=-1) 
	 		if(cnt&1) ans+=x; else ans-=x;
	 	}
	 	printf("%lld\n",n-1-ans);
 	}  //2 3 4 5 6
 	//7 3 1 1 1
 	//x x   x x
	return 0;
}