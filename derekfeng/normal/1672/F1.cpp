#include<bits/stdc++.h>
using namespace std;
int t,n,p[200005];
vector<int>v[200005],all;
int ans[200005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]),v[p[i]].push_back(i);
		for(int i=1;i<=n;i++)if(!v[i].empty())all.push_back(i);
		while(!all.empty()){
			vector<pair<int,int> >t;
			vector<int>nall;
			for(auto x:all)t.push_back({x,v[x].back()}),v[x].pop_back();
			for(int i=0;i<t.size();i++)ans[t[i].second]=t[(i+1)%t.size()].first;
			for(auto x:all)if(v[x].size())nall.push_back(x);
			swap(all,nall);
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	}
}