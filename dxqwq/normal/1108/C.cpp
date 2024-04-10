// Problem: D. Diverse Garland
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/D
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
}//eternal_loveti
char s[1000003];
int a[1000003];
int ans=0,n=read();
void check(char A,char B,char C)
{
	int t=0;
	t=0;
	for(int i=1; i<=n; i++)
	{
		if(i%3==1) {if(s[i]==A) ++t;}
		else if(i%3==2) {if(s[i]==B) ++t;}
		else {if(s[i]==C) ++t;}
	}
	ans=max(ans,t);
	return ;
}
void check1(char A,char B,char C)
{
	int t=0;
	t=0;
	for(int i=1; i<=n; i++)
	{
		if(i%3==1) {if(s[i]==A) ++t;}
		else if(i%3==2) {if(s[i]==B) ++t;}
		else {if(s[i]==C) ++t;}
	}
	if(ans==t)
	{
		printf("%lld\n",n-ans);
		for(int i=1; i<=n; i++) if(i%3==1) printf("%c",A);
		else if(i%3==2) printf("%c",B);
		else printf("%c",C);
		exit(0);
	}
	return ;
}
signed main()
{
	scanf("%s",s+1);
	check('R','G','B');
	check('R','B','G');
	check('G','R','B');
	check('G','B','R');
	check('B','G','R');
	check('B','R','G');
	check1('R','G','B');
	check1('R','B','G');
	check1('G','R','B');
	check1('G','B','R');
	check1('B','G','R');
	check1('B','R','G');
    return 0;
}