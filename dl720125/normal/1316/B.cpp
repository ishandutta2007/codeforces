#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		string rev="";
		for(int i=s.size()-1;i>=0;i--) rev+=s[i];
		int k=-1;
		string ans="";
		for(int i=1;i<=n;i++){
			string x=s.substr(i-1);
			if(i>1){
				int num=n-i+1;
				if(num%2==1) x+=rev.substr(s.size()-i+1);
				else x+=s.substr(0,i-1);
			}
			if(k==-1||x<ans){
				ans=x;
				k=i;
			}
		}
		cout<<ans<<endl<<k<<endl;
	}
	return 0;
}