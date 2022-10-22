#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 1000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int p,q;cin>>p>>q;
		int t=q;
		vector<int> v;
		for(int i=2;i*i<=q;i++) if(t%i==0){
			v.push_back(i);
			while(t%i==0) t/=i;
		}
		if(t>1) v.push_back(t);
		int a1=p,a2=q,val=INF;
		bool flag=true;
		for(int i=0;i<v.size();i++){
			int cnt1=0,cnt2=0;
			while(a1%v[i]==0) a1/=v[i],cnt1++;
			while(a2%v[i]==0) a2/=v[i],cnt2++;
			if(cnt1<cnt2) flag=false;
			else{
				int x=cnt1-cnt2+1,now=1;
				while(x--) now*=v[i];
				val=min(val,now);
			}
		}
		if(!flag) cout<<p<<'\n';
		else cout<<p/val<<'\n';
	}
	return 0;
}