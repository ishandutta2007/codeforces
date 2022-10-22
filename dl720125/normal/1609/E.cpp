#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int sum1[400010],sum2[400010],sum3[400010],val1[400010],val2[400010],val3[400010];
char c[100010];

inline void pushup(int o)
{
	int l=o*2,r=o*2+1;
	sum1[o]=sum1[l]+sum1[r];
	sum2[o]=sum2[l]+sum2[r];
	sum3[o]=sum3[l]+sum3[r];
	val1[o]=min(val1[l]+sum2[r],val1[r]+sum1[l]);
	val2[o]=min(val2[l]+sum3[r],val2[r]+sum2[l]);
	val3[o]=min(val1[l]+val2[r],min(val3[l]+sum3[r],val3[r]+sum1[l]));
}

inline void build(int o,int l,int r)
{
	if(l<r){
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
		pushup(o);
	}
	else{
		sum1[o]=sum2[o]=sum3[o]=0;
		val1[o]=val2[o]=val3[o]=INF;
		if(c[l]=='a') sum1[o]++,val1[o]=0;
		if(c[l]=='b') sum2[o]++,val2[o]=0;
		if(c[l]=='c') sum3[o]++;
	}
}

inline void update(int o,int l,int r,int x,char ch)
{
	if(r<x||l>x) return;
	if(x<=l&&r<=x){
		sum1[o]=sum2[o]=sum3[o]=0;
		val1[o]=val2[o]=val3[o]=INF;
		if(ch=='a') sum1[o]++,val1[o]=0;
		if(ch=='b') sum2[o]++,val2[o]=0;
		if(ch=='c') sum3[o]++;
		return;
	}
	int mid=(l+r)/2;
	update(o*2,l,mid,x,ch);
	update(o*2+1,mid+1,r,x,ch);
	pushup(o);
}

signed main()
{
	ios::sync_with_stdio(false);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>c[i];
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int pos;char ch;cin>>pos>>ch;
		update(1,1,n,pos,ch);
		cout<<min(sum1[1],min(val1[1],val3[1]))<<'\n';
	}
	return 0;
}