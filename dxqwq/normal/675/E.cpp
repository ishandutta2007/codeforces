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
int n=read(),a[100003],st[100003][18];
inline int pmax(int x,int y){if(a[x]>=a[y]) return x; return y;}
inline void init(int l)
{
	st[l][0]=l;
	for(int i=1; i<=17; i++) st[l][i]=pmax(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
}
inline int query(int l,int r)
{
	int L=log(r-l+1)/log(2);
	return pmax(st[l][L],st[min(r-(1<<L)+1,n)][L]);
}
long long dp[100003];
signed main()
{
	dp[n-1]=1,a[n]=n;
	for(int i=1; i<n; i++) a[i]=read();
	for(int i=n; i>=1; i--) init(i);
	for(int i=n-2,pos; i>=1; i--) pos=query(i+1,a[i]),dp[i]=dp[pos]-(a[i]-pos)+n-i;
	long long ans=0;
	for(int i=1; i<n; i++) ans+=dp[i];
	printf("%lld\n",ans);
	return 0;
}