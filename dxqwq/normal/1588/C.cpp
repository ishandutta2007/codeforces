//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		map<int,int> mp;
		int s=0;
		for(int i=1,d=0; i<=n; ++i)
		{
			if(i&1) 
			{
				d+=a[i];
				++mp[a[i]-d];
				while(!mp.empty())
				{
					auto x=mp.begin();
					if(x->first+d<0)
					mp.erase(mp.begin());
					else break;
				}
			}
			else
			{
				d-=a[i];
				++mp[-a[i]-d];
				while(!mp.empty())
				{
					auto x=mp.rbegin();
					if(x->first+d>0) 
					mp.erase(mp.find(mp.rbegin()->first));
					else break;
				}
			}
			s+=mp[-d];
		}
		printf("%lld\n",s);
	}
	return 0;
}