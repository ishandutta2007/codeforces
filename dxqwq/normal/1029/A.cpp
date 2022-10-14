// Problem: A. Many Equal Substrings
// Contest: Codeforces - Codeforces Round #506 (Div. 3)
// URL: https://codeforces.com/contest/1029/problem/A
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
	int n=read(),k=read();
	int Ans=1;
	scanf("%s",s+1);
	for(int i=1; i<n; i++)
	{
		//i=1
		//1 -> n
		//i=2
		//1 -> n-1
		int X=n-i;
		bool FF=1;
		for(int i=1; i+X<=n; i++) if(s[i]!=s[i+X]) FF=0;
		if(FF)
		{
			Ans=i+1;
		}
	}
	for(int i=1; i<=n; i++) printf("%c",s[i]);
	for(int i=1; i<k; i++)
	{
		for(int j=Ans; j<=n; j++) printf("%c",s[j]);
	}
    return 0;
}