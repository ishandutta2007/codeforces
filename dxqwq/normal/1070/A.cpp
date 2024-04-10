// Problem: A. Find a Number
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1070/problem/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int d[5003][503];
pair<int,int> lst[5003][503];
//use j mod k
signed main()
{
	int m=read(),n=read();
	queue<pair<int,int>> q;
	for(int i=1; i<=9; ++i)	
		d[i][i%m]=1,q.push(make_pair(i,i%m));
	while(!q.empty())
	{
		auto i=q.front();
		q.pop();
		for(int j=0; j<=9&&i.first+j<=n; ++j)
			if(!d[i.first+j][(i.second*10+j)%m]) 
				d[i.first+j][(i.second*10+j)%m]=
				d[i.first][i.second]+1,
				lst[i.first+j][(i.second*10+j)%m]=i,
				q.push(make_pair(i.first+j,(i.second*10+j)%m));
	}
	if(d[n][0])
	{
		auto i=make_pair(n,0);
		stack<int> st;
		while(i.first)
		{
			st.push(i.first-lst[i.first][i.second].first);
			i=lst[i.first][i.second];
		}
		while(!st.empty()) printf("%d",st.top()),st.pop();
		puts("");
		return 0;
	}
	else puts("-1");
	return 0;
}