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

int l[200010],ans;
char c[200010];

inline void dfs(int L,int R)
{
	if(L>R) return;
	ans++;
	int now=L;
	while(now<=R){
		int nxt=l[now];
		dfs(now+1,nxt-1);
		now=nxt+1;
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=2*n;i++) cin>>c[i];
		stack<int> s;
		for(int i=1;i<=2*n;i++){
			if(c[i]=='(') s.push(i);
			else{
				l[s.top()]=i;
				s.pop();
			}
		}
		ans=0;dfs(1,2*n);
		cout<<ans<<'\n';
	}
	return 0;
}