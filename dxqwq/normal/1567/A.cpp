// Problem: A. Domino Disaster
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: One-Four Overload
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1567/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
signed main()
{
	for(int T=read();T--;)
	{
		string f;
		cin>>f;
		cin>>f;
		for(char&c:f) if(c=='U') c='D'; else if(c=='D') c='U';
		cout<<f<<endl;
	}
	return 0;
}