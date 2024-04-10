#include<bits/stdc++.h>
using namespace std;
int n,q,ans[131072];
vector<pair<int,int> >v[262144];
void add(int x,int y,int l,int r,int _l,int _r,int k){
	if(l>_r||r<_l)return;
	if(l<=_l&&_r<=r){
		v[k].push_back({x,y});
		return;
	}
	add(x,y,l,r,_l,_l+_r>>1,k<<1);
	add(x,y,l,r,_l+_r+1>>1,_r,k<<1|1);
}
bool ok=1;
int fa[100003],dis[100003],sz[100003];
pair<int,int>fnd(int x){
	if(fa[x]==x)return {x,0};
	pair<int,int>ret=fnd(fa[x]);
	ret.second^=dis[x];return ret;
}
void solve(int k){
	bool tmp=ok;
	vector<int>gx,gy;
	for(int i=0;i<v[k].size();i++){
		if(!ok)continue;
		pair<int,int>x=fnd(v[k][i].first),y=fnd(v[k][i].second);
		if(sz[x.first]<sz[y.first])swap(x,y);
		if(x.first!=y.first){
			gx.push_back(x.first);
			gy.push_back(y.first);
			sz[x.first]+=sz[y.first];
			dis[y.first]=(x.second^y.second^1);
			fa[y.first]=x.first;
		}else
			if(x.second^y.second^1)
				ok=0;
	}
	if(k>131071)
		ans[k-131072]=ok;
	else
		solve(k<<1),solve(k<<1|1);
	while(gx.size()){
		fa[gy.back()]=gy.back();
		dis[gy.back()]=0;
		sz[gx.back()]-=sz[gy.back()];
		gx.pop_back();
		gy.pop_back();
	}
	ok=tmp;
}
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++)fa[i]=i,sz[i]=1;
	set<pair<int,int> >st;
	map<pair<int,int>,int>mp;
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		if(st.find({x,y})==st.end())
			st.insert({x,y}),
			mp[{x,y}]=i;
		else{
			add(x,y,mp[{x,y}],i-1,0,131071,1);
			st.erase({x,y});
		}
	}
	for(auto it=st.begin();it!=st.end();it++)
		add((*it).first,(*it).second,mp[*it],q-1,0,131071,1);
	solve(1);
	for(int i=0;i<q;i++)
		if(ans[i])
			printf("YES\n");
		else
			printf("NO\n");
}