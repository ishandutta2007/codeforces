// Problem: E. Game with String
// Contest: Codeforces - Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// URL: https://codeforces.com/contest/931/problem/E
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
char s[10003];
int a[26][5003][26];
//i,jk
int p[26];
signed main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0; i<n; i++)
	{
		++p[s[i]-'a'];
		for(int j=1; j<n; ++j) ++a[s[i]-'a'][j][s[(i+j)%n]-'a'];
	}	
	double ans=0;
	for(int i=0; i<26; ++i)
	{
		int h=0;
		for(int j=1; j<n; j++) 
		{
			int cur=0;
			for(int k=0; k<26; ++k) if(a[i][j][k]==1) ++cur;
			h=max(h,cur);
		}
		ans+=1.0*h/n;
	}
	printf("%.10lf\n",ans);
    return 0;
}