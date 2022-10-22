#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF1 1000000007
#define INF2 1000000000000000007ll
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

int n,t,g[200010],c[200010],d[200010],a[200010],vall[800010];
int minv[4000010];
bool tag[4000010];
long long sum[200010],dp[200010];
map<long long,int> mp,pm;
map<int,int> mp1,mp2,pm1;

inline void build(int o,int l,int r)
{
	minv[o]=INF1;
	if(l<r){
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r); 
	}
}

inline void update(int o,int l,int r,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		minv[o]=v;
		return;
	}
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,v);
	update(o*2+1,mid+1,r,x,y,v);
}

inline int query(int o,int l,int r,int x)
{
	if(l==r) return minv[o];
	int mid=(l+r)/2;
	if(x<=mid) return min(minv[o],query(o*2,l,mid,x));
	else return min(minv[o],query(o*2+1,mid+1,r,x));
}

inline void build1(int o,int l,int r)
{
	minv[o]=0;tag[o]=0;
	if(l<r){
		int mid=(l+r)/2;
		build1(o*2,l,mid);
		build1(o*2+1,mid+1,r);
	}
}

inline void update2(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag[o]=1;minv[o]=1;
		return;
	}
	int mid=(l+r)/2;
	if(tag[o]) tag[o*2]=1,minv[o*2]=1;
	if(tag[o]) tag[o*2+1]=1,minv[o*2+1]=1;
	tag[o]=0;
	update2(o*2,l,mid,x,y);
	update2(o*2+1,mid+1,r,x,y);
	minv[o]=min(minv[o*2],minv[o*2+1]);
}

inline int query2(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return -1;
	if(x<=l&&r<=y){
		if(minv[o]==1) return -1;
		if(l==r) return l;
		int mid=(l+r)/2;
		if(tag[o]) tag[o*2]=1,minv[o*2]=1;
		if(tag[o]) tag[o*2+1]=1,minv[o*2+1]=1;
		tag[o]=0;
		int res=query2(o*2+1,mid+1,r,x,y);
		if(res!=-1) return res;
		return query2(o*2,l,mid,x,y);
	}
	int mid=(l+r)/2;
	if(tag[o]) tag[o*2]=1,minv[o*2]=1;
	if(tag[o]) tag[o*2+1]=1,minv[o*2+1]=1;
	tag[o]=0;
	int res=query2(o*2+1,mid+1,r,x,y);
	if(res!=-1) return res;
	return query2(o*2,l,mid,x,y);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>g[i]>>c[i];
	for(int i=1;i<=n-1;i++) cin>>d[i];
	for(int i=1;i<=n;i++){
		a[i]=(a[i-1]+d[i-1])%t;
	}
	for(int i=1;i<=n;i++){
		a[i]=(a[i]+c[i])%t;
	}
	for(int i=1;i<=n-1;i++) sum[i]=sum[i-1]+1ll*d[i];
	mp[1ll]=1;mp[3ll*t]=1;
	for(int i=n;i>=1;i--){
		long long L1=-1ll*(t-1-a[i])+1ll*t,R1=-1ll*(g[i]-a[i])+1ll*t;
		long long L2=1ll*a[i]+1ll+1ll*t,R2=1ll*(t-g[i])+1ll*a[i]+1ll*t;
		mp[L1]=1;mp[R1]=1;mp[L2]=1;mp[R2]=1;mp[1ll*a[i]+1ll*t]=1;
	}
	int cnt=0;
	for(map<long long,int>::iterator it=mp.begin();it!=mp.end();it++){
		cnt++;pm[it->first]=cnt;
	}
	build(1,1,cnt);
	for(int i=n;i>=1;i--){
		int now=query(1,1,cnt,pm[1ll*a[i]+1ll*t]);
		if(now==INF1) dp[i]=sum[n-1]-sum[i-1];
		else{
			int pos=(a[now]-a[i]+t)%t;
			dp[i]=sum[now-1]-sum[i-1]+dp[now]+1ll*(t-pos);
		}
		long long L1=-1ll*(t-1-a[i])+1ll*t,R1=-1ll*(g[i]-a[i])+1ll*t;
		long long L2=1ll*a[i]+1ll+1ll*t,R2=1ll*(t-g[i])+1ll*a[i]+1ll*t;
		update(1,1,cnt,pm[L1],pm[R1],i);
		update(1,1,cnt,pm[L2],pm[R2],i);
	}
	mp1[1]=1;mp1[t]=1;
	for(int i=1;i<=n;i++){
		int L1=g[i]-a[i],R1=t-1-a[i];
		mp1[max(L1,0)+1]=1;mp1[R1+1]=1;
		if(L1<0){
			mp1[L1+t+1]=1;mp1[t-1+1]=1;
		}
	}
	int cnt1=0,pre=0;
	for(map<int,int>::iterator it=mp1.begin();it!=mp1.end();it++){
		mp2[it->first]=1;
		if(pre<(it->first)-1) mp2[(it->first)-1]=1;
	}
	for(map<int,int>::iterator it=mp2.begin();it!=mp2.end();it++){
		cnt1++;pm1[it->first]=cnt1;vall[cnt1]=(it->first);
	}
	build1(1,1,cnt1);
	long long ans=INF2;
	for(int i=1;i<=n;i++){
		int L1=g[i]-a[i],R1=t-1-a[i];
		int cur=query2(1,1,cnt1,pm1[max(L1,0)+1],pm1[R1+1]);
		update2(1,1,cnt1,pm1[max(L1,0)+1],pm1[R1+1]);
		if(L1<0){
			if(cur==-1) cur=query2(1,1,cnt1,pm1[L1+t+1],pm1[t-1+1]);
			update2(1,1,cnt1,pm1[L1+t+1],pm1[t-1+1]);
		}
		if(cur!=-1){
			cur=vall[cur];cur--;
			int pos=(cur+a[i])%t;
			long long now=dp[i]+sum[i-1]+1ll*(t-pos);
			ans=min(ans,now);
		}
	}
	int cur=query2(1,1,cnt1,1,cnt1);
	if(cur!=-1){
		ans=min(ans,sum[n-1]);
	}
	cout<<ans<<'\n';
	return 0;
}