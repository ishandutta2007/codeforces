#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int num=0;
		for(int i=1;i<=n;i++) cin>>a[i],num^=a[i];
		bool flag=true;
		for(int i=30;i>=0;i--){
			if(num&(1<<i)){
				int cnt=0;
				for(int j=1;j<=n;j++) if(a[j]&(1<<i)) cnt++;
				if((cnt-1)%4==0){
					cout<<"WIN\n";
				}
				else{
					if(n%2==1) cout<<"LOSE\n";
					else cout<<"WIN\n"; 
				}
				flag=false;
				break;
			}
		}
		if(flag) cout<<"DRAW\n";
	}	
	return 0;
}