// Problem: E. Best Pair
// Contest: Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> v[1000003];
int ind[100003],cnt;
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		map<int,int> mp;
		map<pair<int,int>,bool> mmp;
		for(int i=1; i<=n; ++i) vector<int>().swap(v[i]);
		for(int i=1; i<=n; ++i) ++mp[read()];
		for(int i=1; i<=m; ++i){int x=read(),y=read();
		mmp[make_pair(x,y)]=mmp[make_pair(y,x)]=1;}
		for(auto i:mp) v[i.second].push_back(i.first);
		cnt=0;
		for(int i=1; i<=n; ++i) if(!v[i].empty()) 
		{
			sort(v[i].begin(),v[i].end(),[&](int x,int y)
			{
				return x>y;
			});
			ind[++cnt]=i;
		}
		int ans=0,S=0;
		for(int i=1; i<=cnt; ++i)
			for(int j=1; j<=i; ++j)
				for(int k:v[ind[i]])
				{
					++S;
					auto it=v[ind[j]].begin();
					while(it!=v[ind[j]].end())
						if(k==*it||mmp.find(make_pair(k,*it))!=mmp.end()) ++it;
					else
					{
						ans=max(ans,(ind[i]+ind[j])*(k+*it));
						break;
					}
				}
		printf("%lld\n",ans);
	}
	return 0;
}