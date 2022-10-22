#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int sx[210],sy[210],fx[210],fy[210];

signed main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>sx[i]>>sy[i];
	for(int i=1;i<=k;i++) cin>>fx[i]>>fy[i];
	cout<<n-1+m-1+n*m-1<<endl;
	for(int i=1;i<=n-1;i++) cout<<'U';
	for(int i=1;i<=m-1;i++) cout<<'L';
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m-1;j++) cout<<'R';
			if(i<n) cout<<'D'; 
		}
		else{
			for(int j=1;j<=m-1;j++) cout<<'L';
			if(i<n) cout<<'D';
		}
	}
	cout<<endl;
	return 0;
}