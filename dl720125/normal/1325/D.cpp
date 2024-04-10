#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int u,v;
	cin>>u>>v;
	if(u>v){
		cout<<-1<<endl;
		return 0; 
	}
	if((v-u)%2ll==1){
		cout<<-1<<endl;
		return 0;
	}
	if(u==0&&v==0){
		cout<<0<<endl;
		return 0;
	}
	if(u==v){
		cout<<1<<endl<<u<<endl;
		return 0;
	}
	int p=(v-u)/2ll,num=0ll;
	for(int i=62;i>=0;i--){
		if((u&(1ll<<i))&&(p&(1ll<<i))){
			cout<<3<<endl<<u<<" "<<p<<" "<<p<<endl;
			return 0;
		}
		num=num*2ll+((p&(1ll<<i))>0);
	}
	cout<<2<<endl<<num<<" "<<v-num<<endl;
	return 0;
}