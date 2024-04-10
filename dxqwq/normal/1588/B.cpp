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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
map<pair<int,int>,int> Q;
int query(int l,int r)
{
    if(Q.find(make_pair(l,r))!=Q.end()) return Q[make_pair(l,r)];
	printf("? %lld %lld\n",l,r);
    fflush(stdout);
	return Q[make_pair(l,r)]=read();
}
int qwq(int x)
{
	int l=1,r=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(mid*(mid-1)/2==x) return mid;
		else if(mid*(mid-1)/2<x) l=mid+1;
		else r=mid-1;
	}
	assert(0);
}
signed main()
{
    map<int,int> mp;
	for(int T=read();T--;)
	{
        Q.clear();
		int n=read();
		int l=2,r=n,res=1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(query(1,mid)==0) res=mid,l=mid+1;
            else r=mid-1;
        }
        --res;
        int x=query(res+1,n);
        int A=x-query(res+2,n)+1,B=qwq(x-A*(A-1)/2);
        if(query(res+1,res+A)==A*(A-1)/2) printf("! %lld %lld %lld\n",res+1,res+A+1,res+A+B);
        else printf("! %lld %lld %lld\n",res+1,res+B+1,res+B+A);
        fflush(stdout);
	}
	return 0;
}