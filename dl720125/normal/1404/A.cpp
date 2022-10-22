#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[300010],num[300010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			char c;cin>>c;
			if(c=='?') a[i]=-1;
			else a[i]=c-'0';
		}
		for(int i=0;i<k;i++) num[i]=-1;
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=-1){
				if(num[(i-1)%k]==-1) num[(i-1)%k]=a[i];
				else if(num[(i-1)%k]!=a[i]){
					flag=false;break;
				}
			}
		}
		if(!flag){
			cout<<"NO\n";continue;
		}
		int cnt0=0,cnt1=0;
		for(int i=0;i<k;i++){
			if(num[i]==0) cnt0++;
			if(num[i]==1) cnt1++;
		}
		if(cnt0>k/2||cnt1>k/2){
			cout<<"NO\n";continue;
		}
		cout<<"YES\n";
	}
	return 0;
}