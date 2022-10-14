// Problem: B. Hate "A"
// Contest: Codeforces - Forethought Future Cup - Elimination Round
// URL: https://codeforces.com/contest/1146/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
char s[1000003];
char a[1000003];
char b[1000003];
int la,lb;
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int S=0;
	for(int i=1; i<=n; i++) if(s[i]!='a') ++S;
	if(S&1)
	{
		puts(":(");
		return 0;
	}
	int R=1,cnt=0;
	s[n+1]='b';
	while(1)
	{
		if(s[R]!='a') ++cnt;
		if(cnt*2>S)
		{
			--R;
			break;
		}
		++R;
	}
	for(int i=1; i<=R; ++i) if(s[i]!='a') a[++la]=s[i];
	for(int i=R+1; i<=n; ++i) if(s[i]!='a') b[++lb]=s[i];
	else
	{
		puts(":(");
		return 0;
	}
	assert(la==lb);
	for(int i=1; i<=la; i++) if(a[i]!=b[i])
	{
		puts(":(");
		return 0;
	}
	for(int i=1; i<=R; ++i) printf("%c",s[i]);
	puts("");
    return 0;
}