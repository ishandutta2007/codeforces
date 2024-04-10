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

int n,m,s[200010],t[200010],bit[200010],cnt[200010],pw[200010],rev[200010];

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void add(int p,int v)
{
	while(p<=200000){
		bit[p]+=v;
		p+=p&(-p);
	}
}

inline int sum(int p)
{
	int s=0;
	while(p!=0){
		s+=bit[p];
		p-=p&(-p);
	}
	return s;
}

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<=200000;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[200000]=my_pow(pw[200000],MOD-2);
	for(int i=199999;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++) cnt[s[i]]++;
	int val=1;
	for(int i=1;i<=200000;i++) val=1ll*val*rev[cnt[i]]%MOD;
	for(int i=1;i<=n;i++) add(s[i],1);
	int ans=0,tot=n;
	for(int i=1;i<=m;i++){
		if(tot==0) add1(ans,1);
		else{
			int now=pw[tot-1],u=sum(t[i]-1);
			add1(ans,1ll*now*val%MOD*u%MOD);
		}
		cnt[t[i]]--;
		if(cnt[t[i]]<0) break;
		val=1ll*val*(cnt[t[i]]+1)%MOD;
		add(t[i],-1);tot--;
	}
	cout<<ans<<'\n';
	return 0;
}