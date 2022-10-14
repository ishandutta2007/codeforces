// Problem: C. Phoenix and Towers
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];

signed main()
{
    for(int T=read();T--;)
    {
    	int n=read(),m=read(),k=read();
    	for(int i=1; i<=n; ++i) a[i]=read();
    	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    	puts("YES");
    	for(int i=1; i<=m; ++i)q.push(make_pair(0,i));
    	for(int i=1; i<=n; ++i)
    	{
    		pair<int,int> s=q.top();
    		q.pop();
    		printf("%lld ",s.second);
    		s.first+=a[i];
    		q.push(s);
    	}puts("");
    }
	return 0;
}