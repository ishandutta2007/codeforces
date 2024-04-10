#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=1e5+5;
string s[100004];
map<string,int>mp;
vector<pair<pii,int> >v[N];
int n,q;
int cnt,dfn[N],siz[N],dep[N];
vector<int>r,g[100004];
int ans[N];
void dfs(int x){
	dfn[x]=++cnt,siz[x]=1;
	for(auto y:g[x])dep[y]=dep[x]+1,dfs(y),siz[x]+=siz[y];
	v[dep[x]].push_back({{dfn[x],0},x});
}
int M;
vector<int>bit;
struct BIT{
	void upd(int i,int x){
		for(;i<=M;i+=i&-i)bit[i]+=x;
	}
	int got(int i){
		int res=0;
		for(;i;i-=i&-i)res+=bit[i];
		return res;
	}
	int qry(int l,int r){
		return got(r)-got(l-1);
	}
}fwt;
vector<int>all;
int lb(int x){
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1,fa;i<=n;i++){
		cin>>s[i]>>fa;
		if(fa!=0)g[fa].push_back(i);
		else r.push_back(i);
	}
	for(auto x:r)dfs(x);
	cin>>q;
	for(int i=1,u,k;i<=q;i++){
		cin>>u>>k;
		if(dep[u]+k<n)
			v[dep[u]+k].push_back({{dfn[u]+siz[u]-1,dfn[u]},i});
	}
	for(int i=0;i<n;i++){
		all.clear();
		sort(v[i].begin(),v[i].end());
		for(auto x:v[i]){
			all.push_back(x.fi.fi);
			if(x.fi.se>0)all.push_back(x.fi.se);
		}
		sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
		M=all.size();
		bit.clear(),bit.resize(M+1);
		mp.clear();
		for(auto x:v[i]){
			int R=lb(x.fi.fi);
			if(x.fi.se>0){
				int L=lb(x.fi.se);
				ans[x.se]=fwt.qry(L,R);
			}else{
				string S=s[x.se];
				if(mp[S]!=0){
					int pos=mp[S];
					fwt.upd(pos,-1);
				}
				fwt.upd(R,1);
				mp[S]=R;
			}
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
}