#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
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

int a[100010],pos[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pos[a[i]]=i;
		}
		int cnt=1;
		bool ok=true;
		for(int i=n;i>=1;i--){
			bool flag=true;
			if(a[i]==cnt) cnt++;
			else{
				int loc=pos[cnt];
				for(int j=loc;j<=i;j++){
					if(a[j]!=cnt){
						flag=false;
						break;
					}
					cnt++;
				}
				i=loc;
			}
			if(!flag){
				ok=false;
				break;
			}
		}
		if(!ok) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}