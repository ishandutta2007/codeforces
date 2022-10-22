#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int n,m,l[1000010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<vector<char> > v;
	v.resize(n+1,vector<char>(m+1,' '));
	vector<vector<int> > a;
	a.resize(n+1,vector<int>(m+1,-INF));
	vector<vector<int> > b;
	b.resize(n+1,vector<int>(m+1,INF));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>v[i][j];
	}
	for(int i=1;i<=m;i++) a[1][i]=i;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j>=1&&v[i][j-1]!='X') a[i][j]=max(a[i][j],a[i][j-1]);
			if(v[i-1][j]!='X') a[i][j]=max(a[i][j],a[i-1][j]);
		}
	}
	for(int i=1;i<=n;i++) b[i][1]=1;
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[j][i]=i;
			if(v[j][i-1]!='X') b[j][i]=min(b[j][i],b[j][i-1]);
			if(j>=1&&v[j-1][i]!='X') b[j][i]=min(b[j][i],b[j-1][i]);
		}
	}
	int r=0;
	for(int i=1;i<=m;i++){
		r=max(r,i-1);
		while(r<m){
			bool flag=true;
			for(int j=1;j<=n;j++){
				if(a[j][r+1]==-INF){
					if(b[j][r+1]>i){
						flag=false;break;
					}
				}
			}
			if(flag) r++;
			else break;
		}
		l[i]=r;
	}
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		if(l[x]>=y) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}