#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int a[110],cnt[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(cnt,0ll,sizeof(cnt));
		for(int i=1;i<=n;i++){
			int p=a[i],tot=0ll;
			while(p!=0ll){
				cnt[++tot]+=p%k;
				p/=k;
			}
		}
		bool flag=false;
		for(int i=1;i<=100;i++) if(cnt[i]>1ll){
			cout<<"NO"<<endl;
			flag=true;
			break;
		}
		if(!flag) cout<<"YES"<<endl;
	}	
	return 0;
}