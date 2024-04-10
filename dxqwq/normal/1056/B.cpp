// Problem: B. Divide Candies
// Contest: Codeforces - Mail.Ru Cup 2018 Round 3
// URL: https://codeforces.com/contest/1056/problem/B
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
int a[10003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=min(n,m); ++i)
	a[i*i%m]+=(n-i)/m+1;
	//for(int i=0; i<m; ++i) cout<<a[i]<<endl;
	int ans=a[0]*a[0];
	for(int i=1; i<m; ++i)
	{//1 1 0
		ans+=a[i]*a[m-i];
	}
	cout<<ans<<endl;
    return 0;
}