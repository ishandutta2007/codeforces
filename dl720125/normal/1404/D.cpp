#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,a[1000010],val[1000010],col[1000010];
vector<int> v[1000010],res1,res2;

inline void dfs(int x,int c)
{
	col[x]=c;
	if(c==1) res1.push_back(x);
	if(c==2) res2.push_back(x);
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		if(!col[u]){
			dfs(u,3-c);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	if(n%2==0){
		cout<<"First"<<endl;
		fflush(stdout);
		for(int i=1;i<=n;i++) cout<<i<<" ";
		for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<endl;
		fflush(stdout);
	}
	else{
		cout<<"Second"<<endl;
		fflush(stdout);
		for(int i=1;i<=2*n;i++) cin>>a[i],val[a[i]]=i;
		for(int i=1;i<=2*n;i++){
			if(i!=val[a[i]]){
				v[i].push_back(val[a[i]]);
				v[val[a[i]]].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			v[i].push_back(i+n);
			v[i+n].push_back(i);
		}
		for(int i=1;i<=2*n;i++) if(!col[i]) dfs(i,1);
		long long sum=0ll;
		for(int i=0;i<res1.size();i++) sum+=(long long)res1[i];
		if(sum%(2ll*n)==0ll){
			for(int i=0;i<res1.size();i++) cout<<res1[i]<<" ";
			cout<<endl;
		}
		else{
			for(int i=0;i<res2.size();i++) cout<<res2[i]<<" ";
			cout<<endl;
		}
		fflush(stdout);
	}
	return 0;
}