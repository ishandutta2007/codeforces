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

char c[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>c[i];
	int cnt=0;
	for(int i=1;i<=n-2;i++) if(c[i]=='a'&&c[i+1]=='b'&&c[i+2]=='c') cnt++;
	for(int i=1;i<=q;i++){
		int pos;char ch;cin>>pos>>ch;
		if(pos+2<=n) if(c[pos]=='a'&&c[pos+1]=='b'&&c[pos+2]=='c') cnt--;
		if(pos-1>=1&&pos+1<=n) if(c[pos-1]=='a'&&c[pos]=='b'&&c[pos+1]=='c') cnt--;
		if(pos-2>=1) if(c[pos-2]=='a'&&c[pos-1]=='b'&&c[pos]=='c') cnt--;
		c[pos]=ch;
		if(pos+2<=n) if(c[pos]=='a'&&c[pos+1]=='b'&&c[pos+2]=='c') cnt++;
		if(pos-1>=1&&pos+1<=n) if(c[pos-1]=='a'&&c[pos]=='b'&&c[pos+1]=='c') cnt++;
		if(pos-2>=1) if(c[pos-2]=='a'&&c[pos-1]=='b'&&c[pos]=='c') cnt++;
		cout<<cnt<<'\n';
	}
	return 0;
}