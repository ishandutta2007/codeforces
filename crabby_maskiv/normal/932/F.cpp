#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
struct sgt{
	int l,r,ls,rs,id;
}s[60*N];
int rt[N],P;
ll dp[N],a[N],b[N];
inline ll F(int id,int x){
	return b[id]*x+dp[id];
}
inline int build(int l,int r){
	int p=++P;s[p].l=l;s[p].r=r;
	return p;
}
void chg(int p,int id){
	if(!s[p].id){
		s[p].id=id;
		return;
	}
	if(s[p].l==s[p].r){
		s[p].id=((F(s[p].id,s[p].l)<F(id,s[p].l))?s[p].id:id);
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(b[id]==b[s[p].id]){
		if(dp[id]<dp[s[p].id]) s[p].id=id;
		return;
	}
	if(b[id]<b[s[p].id]){
		if(F(id,mid)<F(s[p].id,mid)){
			if(!s[p].ls) s[p].ls=build(s[p].l,mid);
			chg(s[p].ls,s[p].id);
			s[p].id=id;
		}
		else{
			if(!s[p].rs) s[p].rs=build(mid+1,s[p].r);
			chg(s[p].rs,id);
		}
	}
	else{
		if(F(id,mid)<F(s[p].id,mid)){
			if(!s[p].rs) s[p].rs=build(mid+1,s[p].r);
			chg(s[p].rs,s[p].id);
			s[p].id=id;
		}
		else{
			if(!s[p].ls) s[p].ls=build(s[p].l,mid);
			chg(s[p].ls,id);
		}
	}
}
ll qry(int p,int pos){
	if(!p) return 1e18;
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid) return min(qry(s[p].ls,pos),F(s[p].id,pos));
	else return min(qry(s[p].rs,pos),F(s[p].id,pos));
}
int merge(int x,int y){
	if(!x||!y) return x|y;
	if(s[x].l==s[x].r){
		chg(x,s[y].id);
		return x;
	}
	s[x].ls=merge(s[x].ls,s[y].ls);
	s[x].rs=merge(s[x].rs,s[y].rs);
	chg(x,s[y].id);
	return x;
}
vector<int> g[N];
void dfs1(int u,int last){
	rt[u]=build(-1e5,1e5);
	if(g[u].size()==1&&g[u][0]==last){
		dp[u]=0;
		chg(rt[u],u);
		return;
	}
	for(auto v:g[u]){
		if(v==last) continue;
		dfs1(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
	dp[u]=qry(rt[u],a[u]);
	chg(rt[u],u);
}
int main(){
	int i,j;
	dp[0]=1e18;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1,1);
	for(i=1;i<=n;i++) cout<<dp[i]<<" ";
	return 0;
}