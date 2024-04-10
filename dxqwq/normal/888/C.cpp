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
    scanf("%s",s+1);
    int n=strlen(s+1);
    int ans=n;
    for(int i=0,lst=0; i<26; i++)
    {
    	lst=0;
    	int qwq=0;
    	for(int j=1; j<=n; j++)
    	if(s[j]=='a'+i) 
    	{
    		qwq=max(qwq,j-lst);
    		lst=j;
    	}
    	qwq=max(qwq,n+1-lst);
    	ans=min(ans,qwq);
    }
    printf("%lld\n",ans);
    return 0;
}