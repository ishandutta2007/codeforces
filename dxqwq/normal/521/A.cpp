// Problem: A. DNA Alignment
// Contest: Codeforces - Codeforces Round #295 (Div. 1)
// URL: https://codeforces.com/contest/521/problem/A
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
char s[100003];
const int p=1000000007;
const int mod=1e9+7;
inline int qpow(int s,int y,int ret=1)
{
	for(;y;y>>=1,s=1ll*s*s%mod) if(y&1) ret=1ll*ret*s%mod; 
	return ret;
}
signed main()
{
    int n=read();
    scanf("%s",s+1);
    int a=0,b=0,c=0,d=0;
    for(int i=1; i<=n; i++) 
    if(s[i]=='A') ++a;
    else if(s[i]=='G') ++b;
    else if(s[i]=='T') ++c;
    else ++d;
	int xx=max(max(a,b),max(c,d));
	int x=0;
	if(a==xx) ++x;
	if(b==xx) ++x;
	if(c==xx) ++x;
	if(d==xx) ++x;
	printf("%lld\n",qpow(x,n));
	return 0;
}