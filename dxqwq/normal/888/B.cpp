// Problem: B. Buggy Robot
// Contest: Codeforces - Educational Codeforces Round 32
// URL: https://codeforces.com/contest/888/problem/B
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
char s[1000003];
signed main()
{
    int n=read();
    scanf("%s",s+1);
    int ans=0,x1=0,y1=0,x2=0,y2=0;
    for(int i=1; i<=n; i++)
    {
    	if(s[i]=='U') ++y1;
    	if(s[i]=='D') ++y2;
    	if(s[i]=='L') ++x1;
    	if(s[i]=='R') ++x2;
    }
    printf("%d\n",min(x1,x2)*2+min(y1,y2)*2);
	return 0;
}