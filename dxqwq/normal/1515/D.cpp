// Problem: D. Phoenix and Socks
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int c1[1000003];
int c2[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	int l=read(),r=read();
    	for(int i=1; i<=n; ++i) c1[i]=c2[i]=0;
    	for(int i=1; i<=l; ++i) ++c1[read()];
    	for(int i=1; i<=r; ++i) ++c2[read()];
    	int ans=0,N=n/2;
    	int L=0,R=0;
    	int M1=0,M2=0;
    	for(int i=1; i<=n; ++i) 
    	{
    		int A=min(c1[i],c2[i]);
    		c1[i]-=A,c2[i]-=A,N-=A;
    		if(c1[i])
    		{
    			int M=c1[i]/2;M1+=M;
    			L+=c1[i];
    		}
    		else if(c2[i])
    		{
    			int M=c2[i]/2;M2+=M;
    			R+=c2[i];
    		}
    	}
    	if(L>R)
    	{
    		ans+=R;
    		N-=R;
    		M1=min(M1,N);
    		ans+=M1;
    		ans+=(N-M1)*2;
    	}
    	else
    	{
    		ans+=L;
    		N-=L;
    		M2=min(M2,N);
    		ans+=M2;
    		ans+=(N-M2)*2;
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}