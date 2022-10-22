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

int nxt[110],p[110];

inline void dfs(int x,int cnt)
{
	p[x]=cnt;
	if(nxt[x]) dfs(nxt[x],cnt+1);
}

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	int root=-1;
	for(int i=1;i<=n;i++){
		cout<<'?';
		for(int j=1;j<=n;j++){
			if(j!=i) cout<<' '<<2;
			else cout<<' '<<1;
		}
		cout<<'\n';
		fflush(stdout);
		int x;cin>>x;
		if(x==0) root=i;
		else if(x!=i) nxt[x]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<'?';
		for(int j=1;j<=n;j++){
			if(j!=i) cout<<' '<<1;
			else cout<<' '<<2;
		}
		cout<<'\n';
		fflush(stdout);
		int x;cin>>x;
		if(x!=0&&x!=i) nxt[i]=x;
	}
	dfs(root,1);
	cout<<'!';
	for(int i=1;i<=n;i++) cout<<' '<<p[i];
	cout<<'\n';
	fflush(stdout);
	return 0;
}