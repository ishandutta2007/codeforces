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

int pw[200010],rev[200010];
map<string,int> mp;

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

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
	if(x<0) x+=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	pw[0]=1;
	for(int i=1;i<=2*n;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[2*n]=my_pow(pw[2*n],MOD-2);
	for(int i=2*n-1;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	bool flag1=true,flag2=true;
	int u=1,tot0=0,tot1=0;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		int k=2;
		if(s[0]=='W'||s[1]=='B') flag1=false,k--;
		if(s[0]=='B'||s[1]=='W') flag2=false,k--;
		if(s[0]=='W') tot0++;
		if(s[0]=='B') tot1++;
		if(s[1]=='W') tot0++;
		if(s[1]=='B') tot1++; 
		u=1ll*u*k%MOD;
		mp[s]++;
	}
	int ans=flag1+flag2;
	add(ans,-u);
	for(int i=0;i<=2*n-tot0-tot1;i++){
		if(tot0+i==n){
			add(ans,calc(2*n-tot0-tot1,i));
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}