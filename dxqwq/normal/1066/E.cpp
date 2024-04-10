// Problem: E. Binary Numbers AND Sum
// Contest: Codeforces - Codeforces Round #515 (Div. 3)
// URL: https://codeforces.com/contest/1066/problem/E
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
char s[1000003];
char t[1000003];
int G[1000003];
const int p=998244353;
signed main()
{
	int n=read();
	int m=read();
	scanf("%s",s+1);
	scanf("%s",t+1);
	int ans=0,x=0;
	int i=n-m+1,j=1;
	G[0]=1;
	for(int i=1; i<=1000000; i++) G[i]=(G[i-1]<<1)%p;
	for(;i<=n&&j<=m;++i,++j)
	{
		if(t[j]=='1') ++x;
		if(i>0&&s[i]=='1') ans+=G[m-j]*x%p;
		ans%=p;
	}
	printf("%lld\n",ans);
    return 0;
}