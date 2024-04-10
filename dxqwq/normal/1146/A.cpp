// Problem: A. Love "A"
// Contest: Codeforces - Forethought Future Cup - Elimination Round
// URL: https://codeforces.com/contest/1146/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char s[100003];
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int c=0;
for(int i=1; i<=n; i++) if(s[i]=='a') ++c;
    printf("%lld\n",min(c*2-1,n));
    return 0;
}