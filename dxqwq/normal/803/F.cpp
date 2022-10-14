// Problem: F. Coprime Subsequences
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/F
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
const int p=1e9+7;
int a[100003];
int C[100003];
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int prim[1000003];
int phi[1000003],cnt=0;
bool vis[1000003];
void init()
{
    phi[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(!vis[i]) prim[++cnt]=i,phi[i]=-1;
        for(int j=1; j<=cnt&&prim[j]*i<=1000000; j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break; else phi[i*prim[j]]=-phi[i];
        }
    }
}
signed main()
{init();
	//printf("%lld %lld %lld\n",qp(2,0),qp(2,1),qp(2,2));
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) 
	for(int j=1; j*j<=a[i]; j++) if(a[i]%j==0) 
	{
		++C[j];
		if(j*j!=a[i])
		{
			++C[a[i]/j];
		}
	}
	int ans=0;
	for(int i=1; i<=100000; i++) C[i]=qp(2,C[i])-1;
	for(int i=1; i<=100000; i++) 
	{
		if(phi[i]==1) ans=(ans+C[i])%p;
		else if(phi[i]==-1)ans=(ans+p-C[i])%p;
		//printf("%lld ",phi[i]);
	}
	printf("%lld\n",(ans)%p);
    return 0;
}