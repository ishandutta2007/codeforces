#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,q,a[100010],b[100010];
long long sum[100010],maxv[400010],minv[400010];

inline void build(int o,int l,int r)
{
	if(l==r) maxv[o]=minv[o]=sum[l];
	else{
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
		maxv[o]=max(maxv[o*2],maxv[o*2+1]);
		minv[o]=min(minv[o*2],minv[o*2+1]);
	}
}

inline long long query1(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return INF;
	if(x<=l&&r<=y) return minv[o];
	long long res=INF;
	int mid=(l+r)/2;
	res=min(res,query1(o*2,l,mid,x,y));
	res=min(res,query1(o*2+1,mid+1,r,x,y));
	return res;
}

inline long long query2(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return -INF;
	if(x<=l&&r<=y) return maxv[o];
	long long res=-INF;
	int mid=(l+r)/2;
	res=max(res,query2(o*2,l,mid,x,y));
	res=max(res,query2(o*2+1,mid+1,r,x,y));
	return res; 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) a[i]-=b[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+1ll*a[i];
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		if(sum[r]-sum[l-1]!=0ll){
			cout<<-1<<'\n';continue;
		}
		long long val1=query1(1,1,n,l,r)-sum[l-1],val2=query2(1,1,n,l,r)-sum[l-1];
		if(val2>0ll){
			cout<<-1<<'\n';continue;
		}
		cout<<-val1<<'\n';
	}
	return 0;
}