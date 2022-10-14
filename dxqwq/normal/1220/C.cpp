// Problem: C. Substring Game in the Lesson
// Contest: Codeforces - Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
char s[1000003];
signed main()
{
	//int n=read();
	scanf("%s",s+1);
	int n=strlen(s+1);
	char g='z';
	for(int i=1; i<=n; i++) 
	{
		if(g<s[i]) puts("Ann");
		else puts("Mike");
		g=min(g,s[i]);
	}
    return 0;
}