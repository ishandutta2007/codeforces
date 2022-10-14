// Problem: B. Recursive Queries
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/932/problem/B
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
int g(int x)
{
	if(x<10) return x;
	else 
	{
		int res=1;
		while(x)
		{
			if(x%10>0) res=res*(x%10);
			x/=10;
		}
		return g(res);
	}
}int a[1000003][13];
signed main()
{
	for(int i=1; i<=1000000; ++i) 
	{
		int x=g(i);
		for(int j=1; j<=9; ++j) a[i][j]=a[i-1][j];
	if(x<=9) a[i][x]++;
	}
    for(int T=read(); T--;)
    {
    	int aa=read(),b=read(),c=read();
    	printf("%d\n",a[b][c]-a[aa-1][c]);
    }
	return 0;
}