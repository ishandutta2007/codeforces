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

int n,a[100010],b[100010],pw2[100010],pw[200010],rev[200010];
long long sum1[100010],sum2[100010];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline void add2(int &x,int y)
{
	x+=y;
	if(x<0) x+=MOD;
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
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	pw2[0]=1;
	for(int i=1;i<=100000;i++) pw2[i]=1ll*pw2[i-1]*2%MOD;
	pw[0]=1;
	for(int i=1;i<=200000;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[200000]=my_pow(pw[200000],MOD-2);
	for(int i=199999;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<int> v,g;v.push_back(0);
		for(int i=1;i<=n;i++) if(a[i]!=0) v.push_back(a[i]);
		v.push_back(0);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				g.push_back(cnt+1);cnt=0;
			}
			else cnt++;
		}
		g.push_back(cnt+1);cnt=0;
		sum1[0]=0ll;
		for(int i=0;i<v.size();i++) sum1[i+1]=sum1[i]+1ll*v[i];
		sum2[v.size()+1]=0ll;
		for(int i=v.size()-1;i>=0;i--) sum2[i+1]=sum2[i+2]+1ll*v[i];
		int pos=v.size(),tot=0,ans=0;
		for(int i=1;i<=v.size();i++){
			while(sum2[pos]<sum1[i]) pos--;
			if(pos<=i) break;
			if(sum1[i]!=sum2[pos]) continue;
			int len1=i-1,len2=pos-2,now=0;
			if(len1<len2){
				now=tot;if(i==1) add1(now,1);
				int u;
				if(i>1){
					u=calc(g[len1]+g[len2],max(g[len1],g[len2]));
					add2(u,-1);
				}
				else u=calc(g[len1]+g[len2]-2,max(g[len1],g[len2])-1); 
				add1(ans,1ll*now*u%MOD);
				add1(tot,1ll*now*u%MOD);
			}
			else{
				now=tot;if(i==1) add1(now,1);
				int u;
				if(i>1){
					u=pw2[g[len1]];
					add2(u,-1);
				}
				else u=pw2[g[len1]-2];
				add1(ans,1ll*now*u%MOD);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}