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

int n,q;
int a1[500010],a2[500010],a3[500010];
long long sum1[500010],sum2[500010],sum3[500010],val1[500010],val2[500010],dp[500010],L[500010],R[500010];
long long maxv[2000010],mx1[2000010],mx2[2000010],mxL[2000010],mxR[2000010];
pair<pair<int,int>,int> t[500010];

inline void build(int o,int l,int r)
{
	maxv[o]=-INF;
	if(l<r){
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r); 
	}
}

inline void update(int o,int l,int r,int x,long long v)
{
	if(r<x||l>x) return;
	if(x<=l&&r<=x){
		maxv[o]=v;
		return;
	}
	int mid=(l+r)/2;
	update(o*2,l,mid,x,v);
	update(o*2+1,mid+1,r,x,v);
	maxv[o]=max(maxv[o*2],maxv[o*2+1]);
}

inline long long query(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return -INF;
	if(x<=l&&r<=y) return maxv[o];
	long long res=-INF;
	int mid=(l+r)/2;
	res=max(res,query(o*2,l,mid,x,y));
	res=max(res,query(o*2+1,mid+1,r,x,y));
	return res;
}

inline void build1(int o,int l,int r)
{
	mx1[o]=-INF;
	if(l<r){
		int mid=(l+r)/2;
		build1(o*2,l,mid);
		build1(o*2+1,mid+1,r); 
	}
}

inline void update1(int o,int l,int r,int x,long long v)
{
	if(r<x||l>x) return;
	if(x<=l&&r<=x){
		mx1[o]=v;
		return;
	}
	int mid=(l+r)/2;
	update1(o*2,l,mid,x,v);
	update1(o*2+1,mid+1,r,x,v);
	mx1[o]=max(mx1[o*2],mx1[o*2+1]);
}

inline long long query1(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return -INF;
	if(x<=l&&r<=y) return mx1[o];
	long long res=-INF;
	int mid=(l+r)/2;
	res=max(res,query1(o*2,l,mid,x,y));
	res=max(res,query1(o*2+1,mid+1,r,x,y));
	return res;
}

inline void build2(int o,int l,int r)
{
	if(l==r) mx2[o]=L[l]+R[l],mxL[o]=L[l],mxR[o]=R[l];
	else{
		int mid=(l+r)/2;
		build2(o*2,l,mid);
		build2(o*2+1,mid+1,r);
		mx2[o]=max(max(mx2[o*2],mx2[o*2+1]),mxL[o*2]+mxR[o*2+1]);
		mxL[o]=max(mxL[o*2],mxL[o*2+1]);
		mxR[o]=max(mxR[o*2],mxR[o*2+1]);
	}
}

inline pair<long long,pair<long long,long long> > query2(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return make_pair(-INF,make_pair(-INF,-INF));
	if(x<=l&&r<=y) return make_pair(mx2[o],make_pair(mxL[o],mxR[o]));
	pair<long long,pair<long long,long long> > res1,res2,res;
	int mid=(l+r)/2;
	res1=query2(o*2,l,mid,x,y);
	res2=query2(o*2+1,mid+1,r,x,y);
	res.first=max(max(res1.first,res2.first),res1.second.first+res2.second.second);
	res.second.first=max(res1.second.first,res2.second.first);
	res.second.second=max(res1.second.second,res2.second.second);
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a1[i];
	for(int i=1;i<=n;i++) sum1[i]=sum1[i-1]+1ll*a1[i];
	for(int i=1;i<=n;i++) cin>>a2[i];
	for(int i=1;i<=n;i++) sum2[i]=sum2[i-1]+1ll*a2[i];
	for(int i=1;i<=n;i++) cin>>a3[i];
	for(int i=1;i<=n;i++) sum3[i]=sum3[i-1]+1ll*a3[i];
	for(int i=1;i<=n;i++) val1[i]=sum1[i]-sum2[i-1];
	for(int i=1;i<=n;i++) val2[i]=(sum3[n]-sum3[i-1])-(sum2[n]-sum2[i]);
	build1(1,1,n);
	for(int i=1;i<=n;i++) update1(1,1,n,i,val1[i]);
	for(int i=1;i<=q;i++){
		cin>>t[i].first.second>>t[i].first.first>>t[i].second;
	}
	sort(t+1,t+q+1);
	long long ans=-INF;
	build(1,1,q);
	for(int i=1;i<=q;i++){
		int l=t[i].first.second,r=t[i].first.first,c=t[i].second;
		dp[i]=query1(1,1,n,l,r)-c;
		int pos=lower_bound(t+1,t+q+1,make_pair(make_pair(l-1,0),0))-t;
		if(pos<i){
			dp[i]=max(dp[i],query(1,1,q,pos,i-1)-c);
		}
		update(1,1,q,i,dp[i]);
	}
	for(int i=1;i<=n;i++) L[i]=val1[i],R[i]=val2[i];
	build2(1,1,n);
	for(int i=1;i<=q;i++){
		int l=t[i].first.second,r=t[i].first.first,c=t[i].second;
		ans=max(ans,query2(1,1,n,l,r).first-c);
	}
	for(int i=1;i<=n;i++) L[i]=-INF;
	for(int i=1;i<=q;i++) L[t[i].first.first]=max(L[t[i].first.first],dp[i]);
	build2(1,1,n);
	for(int i=1;i<=q;i++){
		int l=t[i].first.second,r=t[i].first.first,c=t[i].second;
		ans=max(ans,query2(1,1,n,max(l-1,1),r).first-c);
	}
	cout<<ans+sum2[n]<<'\n';
	return 0;
}