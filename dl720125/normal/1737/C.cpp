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

map<pair<int,int>,bool> mp;

inline bool check1(int n,int r1,int c1,int r2,int c2,int r3,int c3)
{
	mp.clear();mp[make_pair(r1,c1)]=1;mp[make_pair(r2,c2)]=1;mp[make_pair(r3,c3)]=1;
	if(mp[make_pair(n,1)]&&mp[make_pair(n,2)]&&mp[make_pair(n-1,1)]) return true;
	return false;
}

inline bool check2(int n,int r1,int c1,int r2,int c2,int r3,int c3)
{
	mp.clear();mp[make_pair(r1,c1)]=1;mp[make_pair(r2,c2)]=1;mp[make_pair(r3,c3)]=1;
	if(mp[make_pair(1,1)]&&mp[make_pair(1,2)]&&mp[make_pair(2,1)]) return true;
	return false;
}

inline bool check3(int n,int r1,int c1,int r2,int c2,int r3,int c3)
{
	mp.clear();mp[make_pair(r1,c1)]=1;mp[make_pair(r2,c2)]=1;mp[make_pair(r3,c3)]=1;
	if(mp[make_pair(1,n)]&&mp[make_pair(1,n-1)]&&mp[make_pair(2,n)]) return true;
	return false;
}

inline bool check4(int n,int r1,int c1,int r2,int c2,int r3,int c3)
{
	mp.clear();mp[make_pair(r1,c1)]=1;mp[make_pair(r2,c2)]=1;mp[make_pair(r3,c3)]=1;
	if(mp[make_pair(n,n)]&&mp[make_pair(n,n-1)]&&mp[make_pair(n-1,n)]) return true;
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,r1,c1,r2,c2,r3,c3,x,y;
		cin>>n>>r1>>c1>>r2>>c2>>r3>>c3>>x>>y;
		if(check1(n,r1,c1,r2,c2,r3,c3)){
			if(x==n||y==1) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(check2(n,r1,c1,r2,c2,r3,c3)){
			if(x==1||y==1) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(check3(n,r1,c1,r2,c2,r3,c3)){
			if(x==1||y==n) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(check4(n,r1,c1,r2,c2,r3,c3)){
			if(x==n||y==n) cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		int rr=0,cc=0;
		if(abs(r1-r2)+abs(c1-c2)==2) rr=r3,cc=c3;
		if(abs(r1-r3)+abs(c1-c3)==2) rr=r2,cc=c2;
		if(abs(r2-r3)+abs(c2-c3)==2) rr=r1,cc=c1;
		if(x%2==rr%2||y%2==cc%2) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}