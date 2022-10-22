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

int x,y,z,r[100010],g[100010],b[100010],ans;

inline void calc(int v1[],int len1,int v2[],int len2,int v3[],int len3)
{
	for(int i=1;i<=len1;i++){
		int val1=v1[i];
		int pos3=lower_bound(v3+1,v3+len3+1,val1)-v3;
		if(pos3>len3) continue;
		int val3=v3[pos3];
		int mid=(val1+val3+1)/2;
		int pos2=lower_bound(v2+1,v2+len2+1,mid)-v2;
		if(pos2<=len2){
			int val2=v2[pos2];
			ans=min(ans,(val1-val2)*(val1-val2)+(val2-val3)*(val2-val3)+(val3-val1)*(val3-val1));
		}
		pos2--;
		if(pos2>=1){
			int val2=v2[pos2];
			ans=min(ans,(val1-val2)*(val1-val2)+(val2-val3)*(val2-val3)+(val3-val1)*(val3-val1));
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>x>>y>>z;
		for(int i=1;i<=x;i++) cin>>r[i];
		for(int i=1;i<=y;i++) cin>>g[i];
		for(int i=1;i<=z;i++) cin>>b[i];
		sort(r+1,r+x+1);sort(g+1,g+y+1);sort(b+1,b+z+1);
		ans=INF;
		calc(r,x,g,y,b,z);
		calc(r,x,b,z,g,y);
		calc(g,y,r,x,b,z);
		calc(g,y,b,z,r,x);
		calc(b,z,r,x,g,y);
		calc(b,z,g,y,r,x);
		cout<<ans<<endl;
	}
	return 0;
}