#include<bits/stdc++.h>
using namespace std;
int n,a[200003],q,mp[200003],lst[200003],nxt[200003],l,r;
long long ans[1000003];
struct BIT{
	long long dat[200003]; 
	BIT(){memset(dat,0,sizeof(dat));}
	long long query(int x){
		long long ret=0;
		while(x){
			ret+=dat[x];
			x-=(x&-x);
		}return ret;
	}
	void add(int x,long long y){
		while(x<=n){
			dat[x]+=y;
			x+=(x&-x);
		}
	}
}tr[2][2];
struct solver{
	vector<pair<int,int> >v[200003],g[200003];
	vector<int>idx[200003];
	void add(int x,int y,int tp){
		y++;
		v[x].push_back({y,tp});
	}
	void query(int x,int y,int id,int tp){
		y++;
		g[x].push_back({y,tp});
		idx[x].push_back(id);
	}
	void solve(){
		for(int i=0;i<n+3;i++){
			for(int j=0;j<v[i].size();j++){
				tr[0][0].add(v[i][j].first,v[i][j].second);
				tr[0][1].add(v[i][j].first,v[i][j].second*v[i][j].first);
				tr[1][0].add(v[i][j].first,v[i][j].second*i);
				tr[1][1].add(v[i][j].first,1ll*v[i][j].second*v[i][j].first*i);
			}
			for(int j=0;j<g[i].size();j++)
				ans[idx[i][j]]+=g[i][j].second*(tr[0][0].query(g[i][j].first)*i*g[i][j].first-tr[1][0].query(g[i][j].first)*g[i][j].first-tr[0][1].query(g[i][j].first)*i+tr[1][1].query(g[i][j].first)); 
		}
	}
}ds;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		mp[a[i]]=i;
	}
	vector<pair<int,int> >v,g;
	v.push_back({0,19260817}); 
	for(int i=1;i<=n;i++){
		while(v.back().second<a[i])
			v.pop_back();
		lst[i]=v.back().first+1;
		v.push_back({i,a[i]});
	}
	v.clear();
	v.push_back({n+1,19260817});
	for(int i=n;i>0;i--){
		while(v.back().second<a[i])
			v.pop_back();
		nxt[i]=v.back().first-1;
		v.push_back(make_pair(i,a[i]));
	}
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=1;j<=sqrt(i-1);j++)
			if(i%j==0){
				if(min(mp[i/j],mp[j])>=lst[mp[i]]&&max(mp[i/j],mp[j])<=nxt[mp[i]])
					v.push_back({min(min(mp[i/j],mp[j]),mp[i]),max(max(mp[i/j],mp[j]),mp[i])});
			}
		//lst[i]<=l<=vf 
		//vfvs
		//vs<=r<=nxt[i]
		sort(v.begin(),v.end());
		g.clear();
		if(v.size()){
			g.push_back(v[0]);
			for(int j=1;j<v.size();j++){
				while(g.size()>0&&g.back().second>v[j].second)
					g.pop_back();
				g.push_back(v[j]);
			}
			int tmp=lst[mp[i]]-1;
			for(int j=0;j<g.size();j++){
				ds.add(tmp,g[j].second-1,1);
				ds.add(tmp,nxt[mp[i]],-1);
				ds.add(g[j].first,g[j].second-1,-1);
				ds.add(g[j].first,nxt[mp[i]],1);
				tmp=g[j].first;
			}
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		ds.query(l-1,l-1,i,1);
		ds.query(l-1,r,i,-1);
		ds.query(r,l-1,i,-1);
		ds.query(r,r,i,1);
	}
	ds.solve();
	for(int i=0;i<q;i++)
		printf("%lld\n",ans[i]);
}