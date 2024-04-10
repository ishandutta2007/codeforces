#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,a[100010],b[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			char c;cin>>c;
			if(c=='0') a[i]=0;
			else a[i]=1;
		}
		for(int i=1;i<=n;i++){
			char c;cin>>c;
			if(c=='0') b[i]=0;
			else b[i]=1;
		}
		vector<int> v;
		int cnt=0;
		for(int i=n;i>=1;i--){
			int x=n-i;
			if(x%2==1){
				int num=a[n-cnt/2];
				num^=1;
				if(num==b[i]){
					v.push_back(1);
					v.push_back(i); 
				}
				else v.push_back(i);
			}
			else{
				int num=a[cnt/2+1];
				if(num==b[i]){
					v.push_back(1);
					v.push_back(i);
				}
				else v.push_back(i);
			}
			cnt++;
		}
		cout<<v.size();
		for(int i=0;i<v.size();i++) cout<<" "<<v[i];
		cout<<'\n';
	}
	return 0;
}