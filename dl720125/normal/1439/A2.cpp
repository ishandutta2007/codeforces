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

int a[110][110];

struct node{
	int xa,ya,xb,yb,xc,yc;
};

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;cin>>c;
				a[i][j]=c-'0';
			}
		}
		vector<node> v;
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m-2;j++){
				if(a[i][j]==1){
					node b;
					b.xa=i;b.ya=j;b.xb=i+1;b.yb=j;b.xc=i+1;b.yc=j+1;
					v.push_back(b);
					a[i][j]^=1;a[i+1][j]^=1;a[i+1][j+1]^=1;
				}
			}
			if(a[i][m-1]==0&&a[i][m]==1){
				node b;
				b.xa=i;b.ya=m;b.xb=i+1;b.yb=m-1;b.xc=i+1;b.yc=m;
				v.push_back(b);
				a[i][m]^=1;a[i+1][m-1]^=1;a[i+1][m]^=1;
			}
			else if(a[i][m-1]==1&&a[i][m]==0){
				node b;
				b.xa=i;b.ya=m-1;b.xb=i+1;b.yb=m-1;b.xc=i+1;b.yc=m;
				v.push_back(b);
				a[i][m-1]^=1;a[i+1][m-1]^=1;a[i+1][m]^=1;
			}
			else if(a[i][m-1]==1&&a[i][m]==1){
				node b;
				b.xa=i;b.ya=m-1;b.xb=i;b.yb=m;b.xc=i+1;b.yc=m-1;
				v.push_back(b);
				a[i][m-1]^=1;a[i][m]^=1;a[i+1][m-1]^=1;
			}
		}
		for(int i=1;i<=m-2;i++){
			if(a[n-1][i]==0&&a[n][i]==1){
				node b;
				b.xa=n;b.ya=i;b.xb=n-1;b.yb=i+1;b.xc=n;b.yc=i+1;
				v.push_back(b);
				a[n][i]^=1;a[n-1][i+1]^=1;a[n][i+1]^=1;
			}
			else if(a[n-1][i]==1&&a[n][i]==0){
				node b;
				b.xa=n-1;b.ya=i;b.xb=n-1;b.yb=i+1;b.xc=n;b.yc=i+1;
				v.push_back(b);
				a[n-1][i]^=1;a[n-1][i+1]^=1;a[n][i+1]^=1;
			}
			else if(a[n-1][i]==1&&a[n][i]==1){
				node b;
				b.xa=n-1;b.ya=i;b.xb=n;b.yb=i;b.xc=n-1;b.yc=i+1;
				v.push_back(b);
				a[n-1][i]^=1;a[n][i]^=1;a[n-1][i+1]^=1;
			}
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==1&&a[n][m-1]==1&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m-1;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m-1]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==0&&a[n][m-1]==0&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m-1;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m-1]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==1&&a[n][m-1]==0&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m-1;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m-1]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==0&&a[n][m-1]==1&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m-1;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m-1]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==0&&a[n][m-1]==0&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==1&&a[n][m-1]==0&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n;b.yb=m-1;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n][m-1]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==0&&a[n][m-1]==1&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==0&&a[n][m-1]==0&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m-1;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m-1]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==1&&a[n][m-1]==1&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==1&&a[n][m-1]==0&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n;b.yb=m-1;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n][m-1]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==0&&a[n][m-1]==1&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==1&&a[n][m-1]==1&&a[n][m]==0){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m-1;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m-1]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==1&&a[n][m-1]==0&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n-1][m]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==1&&a[n-1][m]==0&&a[n][m-1]==1&&a[n][m]==1){
			node b;
			b.xa=n-1;b.ya=m-1;b.xb=n;b.yb=m-1;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n-1][m-1]^=1;a[n][m-1]^=1;a[n][m]^=1;
		}
		if(a[n-1][m-1]==0&&a[n-1][m]==1&&a[n][m-1]==1&&a[n][m]==1){
			node b;
			b.xa=n;b.ya=m-1;b.xb=n-1;b.yb=m;b.xc=n;b.yc=m;
			v.push_back(b);
			a[n][m-1]^=1;a[n-1][m]^=1;a[n][m]^=1;
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++) cout<<v[i].xa<<" "<<v[i].ya<<" "<<v[i].xb<<" "<<v[i].yb<<" "<<v[i].xc<<" "<<v[i].yc<<'\n';
	}
	return 0;
}