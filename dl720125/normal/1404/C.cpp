#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,q,a[300010],val[300010],ans[300010],bit[300010];
vector<pair<int,int> > v[300010];

inline int sum(int p)
{
	int s=0;
	while(p>0){
		s+=bit[p];
		p-=p&(-p);
	}
	return s;
}

inline void add(int p,int v)
{
	while(p<=n){
		bit[p]+=v;
		p+=p&(-p);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<=i) val[i]=i-a[i];
		else val[i]=-1;
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		x++;y=n-y;
		v[y].push_back(make_pair(x,i)); 
	}
	for(int i=1;i<=n;i++){
		if(val[i]!=-1){
			int now=0,num=0;
			for(int j=20;j>=0;j--){
				if(now+(1<<j)<=i){
					if(num+bit[now+(1<<j)]>=val[i]){
						num+=bit[now+(1<<j)];now+=(1<<j);
					}
				}
			}
			if(now>0){
				add(1,1);add(now+1,-1);
			}
		}
		for(int j=0;j<v[i].size();j++){
			ans[v[i][j].second]=sum(v[i][j].first);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n'; 
	return 0;
}