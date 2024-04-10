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

int n,k,f[1010],a[1010][1010],b[1010][1010],val[1010][1010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				char ch;cin>>ch;
				a[i][j]=ch-'0';
				b[i][j]=0;
			}
		}
		for(int i=n-1;i>=-(n-1);i--){
			int nowx,nowy;
			if(i>=0) nowx=i+1,nowy=1;
			else nowx=1,nowy=-i+1;
			int len=n-abs(i);
			len=min(1,k-1-len+1);
			while(nowx<=n&&nowy<=n){
				val[nowx][nowy]=len;
				len++;nowx++;nowy++;
			}
		}
		for(int i=1;i<=n;i++){
			f[i]=1;
			while(f[i]<=n&&a[f[i]][i]==1) f[i]++;
		}
		for(int i=1;i<=k-1;i++){
			int nowx=n,nowy=1;
			while(true){
				a[nowx][nowy]=1;b[nowx][nowy]=1;
				while(f[nowy]<=n&&a[f[nowy]][nowy]==1) f[nowy]++;
				if(nowx==1&&nowy==n) break;
				if(nowy==n||val[nowx][nowy+1]>i) nowx--;
				else if(f[nowy]>=nowx) nowy++;
				else nowx--;
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]==0) tot++;
		if(tot>0){
			cout<<"NO\n";continue;
		}
		cout<<"YES\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout<<b[i][j];
			cout<<'\n';
		}
	}
	return 0;
}