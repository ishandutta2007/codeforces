// Problem: E. Gold Transfer
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/E
// Memory Limit: 256 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int a[1000003],c[1000003];
int fa[1000003][20];
int Get(int x)
{
	for(int i=19; i>=0; --i)
	if(a[fa[x][i]]) x=fa[x][i];
	return x;
}
signed main()
{
	int T=read();
	a[0]=read(),c[0]=read();
    for(int i=1; i<=T; ++i)
    {
    	int op=read();
    	if(op==1)
    	{
    		int f0=read();
    		a[i]=read(),c[i]=read();
    		fa[i][0]=f0;
    		for(int j=1; j<20; ++j) fa[i][j]=fa[fa[i][j-1]][j-1];
    	}
    	else
    	{
    		int x=read(),y=read();
    		int a1=0,a2=0;
    		while(a[x]&&a1<=y)
    		{
    			int k=Get(x);
    			if(a[k]>=y-a1)
    			{
    				a2+=(y-a1)*c[k];
    				a[k]-=(y-a1);
    				a1=y;
    				break;
    			}
    			else
    			{
    				a2+=a[k]*c[k];
    				a1+=a[k];
    				a[k]=0;
    			}
    		}
    		printf("%lld %lld\n",a1,a2);
    		fflush(stdout);
    	}
    }
	return 0;
}