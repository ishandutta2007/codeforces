// Problem: B. DMCA
// Contest: Codeforces - April Fools Day Contest 2021
// URL: https://codeforces.com/contest/1505/problem/B
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
int d(int x)
{
	int res=0;
	while(x) res+=x%10,x/=10;
	return res;
}
signed main()
{
    int n=read();
    while(n>=10)
    {
    	n=d(n);
    }
    printf("%lld\n",n);
	return 0;
}