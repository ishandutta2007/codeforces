#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int n,m,l[100010],pos[100010],maxv[100010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>l[i];
	for(int i=1;i<=m;i++){
		if(i+l[i]-1>n){
			cout<<-1<<endl;
			return 0;
		}
		maxv[i]=max(maxv[i-1],i+l[i]-1);
	}
	if(maxv[m]==n){
		for(int i=1;i<=m;i++) cout<<i<<" ";
		cout<<endl;
		return 0;
	}
	int e=0;
	for(int i=m;i>=1;i--){
		e+=l[i];
		int now=maxv[i-1]+e;
		pos[i]=n-e+1;
		if(now>=n){
			for(int j=1;j<i;j++) cout<<j<<" ";
			for(int j=i;j<=m;j++) cout<<pos[j]<<" ";
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}