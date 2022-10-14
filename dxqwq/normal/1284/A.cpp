// Problem: A. New Year and Naming
// Contest: Codeforces - Hello 2020
// URL: https://codeforces.com/contest/1284/problem/A
// Memory Limit: 1024 MB
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
string a[53],b[53];
signed main()
{
	int n=read(),m=read();
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	for(int T=read();T--;)
	{
		int x=read();
		--x;
		cout<<a[x%n]+b[x%m]<<endl;
	}
    return 0;
}