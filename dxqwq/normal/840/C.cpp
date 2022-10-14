//dp
//QAQ
#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
map<int,int> mp;
int a[503],b[503],p[100003],cnt;
bool vis[100003];
int fac[20005],inv[20005];
const int mod=1e9+7;
inline int qpow(int s,int y,int ret=1)
{
	for(;y;y>>=1,s=1ll*s*s%mod) if(y&1) ret=1ll*ret*s%mod; 
	return ret;
}
inline void init_fac(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;--i) inv[i]=(i+1ll)*inv[i+1]%mod;
}
inline int C(int n,int m){
	if(n<m) return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int f[1003][1003],ans[1003][1003];
signed main()
{
    init_fac(10000);
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=2; i<=100000; i++) 
    {
        if(!vis[i]) 
        {
            vis[i]=1,p[++cnt]=i;
            for(int j=1; i*j<=100000; j++) vis[i*j]=1;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=cnt; j++) while(a[i]%(p[j]*p[j])==0) a[i]/=(p[j]*p[j]);
        ++mp[a[i]];
    }
    cnt=0;
    for(auto x=mp.begin(); x!=mp.end(); x++) b[++cnt]=(*x).second;
    sort(b+1,b+cnt+1),f[0][0]=ans[0][0]=1;
    for(int i=1; i<=500; i++) for(int j=1; j<=500; j++) f[i][j]=f[i-1][j-1]*j%mod+f[i-1][j]*(i-1+j)%mod,f[i][j]%=mod;
    int pre=0;
    for(int i=1; i<=500; pre+=b[i],i++) 
    for(int j=0; j<=pre; j++) for(int k=1; k<=b[i]; k++) for(int l=0; l<=j; l++) 
    ans[i][j+b[i]-k-l]+=ans[i-1][j]*f[b[i]][k]%mod*C(j,l)%mod*C(pre+1-j,k-l),
    ans[i][j+b[i]-k-l]%=mod;
    printf("%lld\n",ans[cnt][0]);
    return 0;
}