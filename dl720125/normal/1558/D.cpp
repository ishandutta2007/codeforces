#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
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

int n,m,x[400010],y[400010],pw[400010],rev[400010];
int cnt,root,sz[400010],l[400010],r[400010],rnd[400010],val[400010],tag[400010];

inline void update(int x)
{
	sz[x]=sz[l[x]]+sz[r[x]]+1;
}

inline void pushdown(int x)
{
	if(tag[x]){
		tag[l[x]]+=tag[x];val[l[x]]+=tag[x];
		tag[r[x]]+=tag[x];val[r[x]]+=tag[x];
		tag[x]=0;
	}
}

inline int newnode(int x)
{
	cnt++;
	sz[cnt]=1;
	rnd[cnt]=rand();
	val[cnt]=x;
	l[cnt]=0;
	r[cnt]=0;
	tag[cnt]=0;
	return cnt;
}

inline int merge(int a,int b)
{
	if(!a||!b) return a+b;
	if(rnd[a]<rnd[b]){
		pushdown(a);
		r[a]=merge(r[a],b);
		update(a);
		return a;
	}
	else{
		pushdown(b);
		l[b]=merge(a,l[b]);
		update(b);
		return b;
	}
}

inline void split(int node,int k,int &a,int &b)
{
	if(!node){
		a=0;b=0;
	}
	else{
		pushdown(node);
		if(val[node]<=k){
			a=node;
			split(r[node],k,r[node],b);
		}
		else{
			b=node;
			split(l[node],k,a,l[node]);
		}
		update(node);
	}
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline int calc(int x,int y)
{
	return 1ll*pw[x]*rev[y]%MOD*rev[x-y]%MOD;
}

signed main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<=400000;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[400000]=my_pow(pw[400000],MOD-2);
	for(int i=399999;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		cnt=0;root=0;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i];
			int A,B,C;
			split(root,y[i]-1,A,B);
			tag[B]++;val[B]++;
			root=merge(merge(A,newnode(y[i])),B);
			split(root,y[i]-2,A,B);
			split(B,y[i]-1,B,C);
			root=merge(A,C);
		}
		cout<<calc(n+n-1-sz[root],n)<<'\n';
	}
	return 0;
}