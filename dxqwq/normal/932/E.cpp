// Problem: E. Team Work
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/932/problem/E
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
const int p=1000000007;
int qp(int x,int y)
{
	int res=1;
	for(int now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
	return res;
}
int f[5003][5003];
//ij
signed main()
{
	//iansi^k
	//ii^k
	f[0][0]=1;
    int n=read(),m=read();
    for(int i=1; i<=m; ++i) for(int j=1; j<=i; ++j) f[i][j]=(f[i-1][j]*j%p+f[i-1][j-1]*(n-j+1)%p)%p; 
    int ans=0;
    for(int i=1; i<=m; i++) ans=(ans+f[m][i]*qp(qp(2,p-2),i))%p;
    printf("%lld\n",ans*qp(2,n)%p);
	return 0;
}