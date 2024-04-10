// Problem: B. The Bits
// Contest: Codeforces - Codeforces Round #502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1017/problem/B
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
char s[1000003],t[1000003];
signed main()
{
	int n=read();
    scanf("%s",s+1);
    scanf("%s",t+1);
    int a=0,b=0,c=0,d=0;
    for(int i=1; i<=n; i++) if(t[i]=='1')
    {
    	if(s[i]=='0') ++a;
    	else ++b;
    }
    else
    {
    	if(s[i]=='0') ++a,++c;
    	else ++b,++d;
    }
    printf("%lld\n",a*d+b*c-c*d);
	return 0;
}