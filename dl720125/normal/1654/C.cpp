#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

int n,a[200010];
map<long long,long long> mp1,mp2;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;mp1.clear();mp2.clear(); 
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		long long sum=0ll;
		for(int i=1;i<=n;i++) sum+=1ll*a[i];
		long long now1=sum,cnt1=1,now2=0,cnt2=0;
		while(true){
			mp2[now1]+=cnt1;
			if(now2!=0) mp2[now2]+=cnt2;
			if(now1==1) break;
			if(now2==1){
				mp2[1]+=cnt1*2+cnt2;
				break;
			}
			if(now2==0){
				if(now1%2==0){
					now1/=2;cnt1*=2;
				}
				else{
					cnt2=cnt1;
					now1=now1/2+1;now2=now1-1;
				}
			}
			else{
				if(now1%2==1){
					now1=now1/2+1;now2=now1-1;
					cnt2=cnt2*2+cnt1;
				}
				else{
					now1=now1/2;now2=now1-1;
					cnt1=cnt1*2+cnt2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			long long now1=1ll*a[i],cnt1=1,now2=0,cnt2=0;
			while(true){
				mp2[now1]-=cnt1;
				if(now2!=0) mp2[now2]-=cnt2;
				if(now1==1) break;
				if(now2==1){
					mp2[1]-=cnt1*2+cnt2;
					break;
				}
				if(now2==0){
					if(now1%2==0){
						now1/=2;cnt1*=2;
					}
					else{
						cnt2=cnt1;
						now1=now1/2+1;now2=now1-1;
					}
				}
				else{
					if(now1%2==1){
						now1=now1/2+1;now2=now1-1;
						cnt2=cnt2*2+cnt1;
					}
					else{
						now1=now1/2;now2=now1-1;
						cnt1=cnt1*2+cnt2;
					}
				}
			}
		}
		bool flag=true;
		for(map<long long,long long>::iterator it=mp2.begin();it!=mp2.end();it++){
			if((it->second)<0ll){
				flag=false;break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}