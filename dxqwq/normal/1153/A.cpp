// Problem: A. Serval and Bus
// Contest: Codeforces - Codeforces Round #551 (Div. 2)
// URL: https://codeforces.com/contest/1153/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

signed main()
{
    int n=read(),t=read();
    int id=1,ans=99999999;
    for(int i=1; i<=n; i++)
    {
    	int x=read(),y=read();
    	if(x>=t)
    	{
    		if(x<ans) ans=x,id=i;
    	}
    	else
    	{
    		int g=(t-x-1)/y+1;
    		x=x+g*y;
    		if(x<ans) ans=x,id=i;
    	}
    }
    printf("%lld\n",id);
	return 0;
}