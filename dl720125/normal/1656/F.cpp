#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 9000000000000000007ll
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

int a[200010],sum1[200010],sum2[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		sum1[1]=0;
		for(int i=2;i<=n-1;i++) sum1[i]=sum1[i-1]+a[i];
		sum2[n]=0;
		for(int i=n-1;i>=2;i--) sum2[i]=sum2[i+1]+a[i];
		int ans=-INF;bool flag=true;
		for(int i=1;i<=n-1;i++){
			int l,r;
			if(i==n-1) l=-INF;
			else l=-a[i+1];
			if(i==1) r=INF;
			else r=-a[i];
			int val=sum1[i]*a[n]+sum2[i+1]*a[1]+a[1]*a[n];
			int rem=sum1[n-1]+a[1]*(n-i)+a[n]*i;
			if(rem>0){
				if(r==INF){
					flag=false;break;
				}
				ans=max(ans,r*rem+val);
			}
			else if(rem<0){
				if(l==-INF){
					flag=false;break;
				}
				ans=max(ans,l*rem+val);
			}
			else ans=max(ans,val);
		}
		if(!flag) cout<<"INF\n";
		else cout<<ans<<'\n';
	}
	return 0;
}