#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[200004];
int L[200004];
vector<int>pos[200004];
vector<pair<int,int> >c[200004];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		vector<int>all;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]),L[i]=i;
			all.push_back(a[i]);
		}
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
		for(int i=1;i<=n+2;i++)pos[i].clear(),c[i].clear();
		for(int i=1;i<=n;i++){
			a[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1;
			pos[a[i]].push_back(i);
		}
		for(int i=1;i<=m;i++){
			int l,r;scanf("%d%d",&l,&r);
			L[r]=min(L[r],l);
		}
		for(int i=n-1;i;i--)L[i]=min(L[i],L[i+1]);
		int mx=n+1;
		multiset<int>rb;
		for(int i=1;i<=n;i++)if(pos[i].size()){
			for(int j=0;j<pos[i].size();j++){
				int x=pos[i][j];
				int k=lower_bound(pos[i].begin(),pos[i].end(),L[x])-pos[i].begin();
				if(j!=k){
					mx=min(mx,pos[i][k+1]),rb.insert(pos[i][j-1]);
					c[pos[i][k]+1].push_back({pos[i][j-1],pos[i][j]});
				}
			}
		}
		if(mx>n){
			puts("0");continue;
		}
		int ans=n;
		for(int i=1;i<=mx;i++){
			for(auto [u,v]:c[i]){
				rb.erase(rb.lower_bound(u));
				rb.insert(v);
			}
			ans=min((*rb.rbegin())-i+1,ans);
		}
		printf("%d\n",ans);
	}
}