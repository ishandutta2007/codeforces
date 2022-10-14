// Problem: E. Maximum Subsequence
// Contest: Codeforces - Educational Codeforces Round 32
// URL: https://codeforces.com/contest/888/problem/E
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
int Aa[23],Bb[23];
int a[1000003],b[1000003];
signed main()
{
    int n=read(),m=read();
    if(n==1)
    {
    	printf("%lld\n",read()%m);
    }
    else
    {
    	int A=n/2,B=n-A;
    	for(int i=1; i<=A; i++) Aa[i]=read();
    	for(int i=1; i<=B; i++) Bb[i]=read();
    	int P=1<<A,Q=1<<B;
    	for(int i=0; i<P; i++) 
    	{
    		int cur=0;
    		for(int j=1; j<=A; j++) if((1<<j-1)&(i)) cur=(cur+Aa[j])%m;
    		a[i]=cur;
    	}
    	sort(a,a+P);
    	for(int i=0; i<Q; i++) 
    	{
    		int cur=0;
    		for(int j=1; j<=B; j++) if((1<<j-1)&(i)) cur=(cur+Bb[j])%m;
    		b[i]=cur;
    	}
    	sort(b,b+Q);
    	int ans=(a[P-1]+b[Q-1])%m;
    	for(int i=0,j=Q-1; i<P; i++)
    	{
    		while(j>=0&&a[i]+b[j]>=m) --j;
    		if(j==-1) break;
    		ans=max(ans,a[i]+b[j]);
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}