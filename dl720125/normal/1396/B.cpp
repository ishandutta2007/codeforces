#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,a[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		priority_queue<int> q;
		for(int i=1;i<=n;i++) q.push(a[i]);
		bool flag=false;
		while(!q.empty()){
			int t=q.top();q.pop();
			if(q.empty()){
				flag=true;break;
			}
			int o=q.top();q.pop();
			t--;o--;
			if(t) q.push(t);
			if(o) q.push(o);
		}
		if(flag) cout<<"T\n";
		else cout<<"HL\n"; 
	}
	return 0;
}