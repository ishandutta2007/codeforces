// Problem: C. Colorful Bricks
// Contest: Codeforces - Avito Cool Challenge 2018
// URL: https://codeforces.com/contest/1081/problem/C
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
	return res;
}
signed main()
{
    int n=read(),m=read(),k=read();
    int ans=m%p;
    for(int i=1; i<=k; i++) ans=ans*(m-1)%p;
    int qwq=1,fz=1;
    for(int i=1; i<=k; i++) fz=fz*(n-i)%p,qwq=qwq*i%p;
    printf("%lld\n",ans*qp(qwq,998244351)%p*fz%p);
	return 0;
}