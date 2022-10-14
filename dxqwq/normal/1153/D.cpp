// Problem: D. Serval and Rooted Tree
// Contest: Codeforces - Codeforces Round #551 (Div. 2)
// URL: https://codeforces.com/contest/1153/problem/D
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
int fa[300003],a[300003];
int t[300003];
vector<int> s[300003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=2; i<=n; i++) fa[i]=read(),s[fa[i]].push_back(i);
    	int N=0;
    	for(int i=n; i>=1; i--)
    	{
    		if(s[i].empty())
    		{
    			t[i]=1;
    			++N;
    			continue;
    		}
    		if(a[i]==1)
    		{
    			int mx=99999999;
    			for(int x:s[i])
    			mx=min(mx,t[x]);
    			t[i]=mx;
    		}
    		else
    		{
    			int sum=0;
    			for(int x:s[i])
    			sum+=t[x];
    			t[i]=sum;
    		}
    	}
    printf("%d\n",N-t[1]+1);
	return 0;
}