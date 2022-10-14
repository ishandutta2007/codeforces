// Problem: A. Cards
// Contest: Codeforces - Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/A
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
	int n=read(),a=0,b=0,c=0,d=0,e=0;
	scanf("%s",s+1);
	for(int i=1; i<=n; i++) if(s[i]=='e') ++a;
	else if(s[i]=='z') ++b;
	else if(s[i]=='o') ++c;
	else if(s[i]=='r') ++d;
	else ++e;
	for(int i=1; i<=e; i++) printf("1 ");
	for(int i=1; i<=b; i++) printf("0 ");
    return 0;
}