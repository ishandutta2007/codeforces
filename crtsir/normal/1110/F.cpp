#include<bits/stdc++.h>
using namespace std;
long long n,Q,dat[1048576],maxm[500003],dis[500003],laz[1048576];
vector<long long>v[500003],G[500003];
long long dfs(long long x,long long dist,long long p){
	long long ret=x;
	dis[x]=dist;
	for(long long i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			ret=max(dfs(v[x][i],dist+G[x][i],x),ret);
	maxm[x]=ret;
	return ret;
}
void pushdown(int x){
	if(laz[x]){
		dat[x*2]+=laz[x];
		laz[x*2]+=laz[x];
		dat[x*2+1]+=laz[x];
		laz[x*2+1]+=laz[x];
		laz[x]=0;
	}
}
void pushup(int x){
	dat[x]=min(dat[x*2],dat[x*2+1]);
}
void change(long long a,long long b,long long k,long long l,long long r,long long chan){
	int rr=min(r,n-1);
	if(rr<a||b<l)return;
	if(a<=l&&rr<=b){
		dat[k]+=chan;
		laz[k]+=chan;
		return;
	}
	pushdown(k);
	change(a,b,k*2,l,(l+r)/2,chan);
	change(a,b,k*2+1,(l+r)/2+1,r,chan);
	pushup(k);
}
long long query(long long a,long long b,long long k,long long l,long long r){
	int rr=min(r,n-1);
	if(rr<a||b<l)return 1e17;
	if(a<=l&&rr<=b)return dat[k];
	pushdown(k);
	return min(query(a,b,k*2,l,(l+r)/2),query(a,b,k*2+1,(l+r)/2+1,r));
}
vector<int>l[500003],r[500003],p[500003];
long long ans[500003],cntt;
void dfs2(int x,int pp){
	for(int i=0;i<p[x].size();i++)ans[p[x][i]]=cntt+query(l[x][i],r[x][i],1,0,524287);
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=pp) 
		{
			cntt+=G[x][i]; 
			change(v[x][i],maxm[v[x][i]],1,0,524287,-G[x][i]-G[x][i]);
			dfs2(v[x][i],x);
			change(v[x][i],maxm[v[x][i]],1,0,524287,G[x][i]+G[x][i]);
			cntt-=G[x][i];
		}
} 
int main(){
	cin>>n>>Q;
	for(long long i=1;i<n;i++){
		long long b,c;scanf("%lld%lld",&b,&c);b--;
		v[i].push_back(b);
		G[i].push_back(c);
		v[b].push_back(i);
		G[b].push_back(c);
	}
	dfs(0,0,-1);
	for(long long i=0;i<1048576;i++)dat[i]=1e17;
	for(long long i=1;i<n;i++)
		if(v[i].size()==1){
			long long now=524288+i;
			dat[now]=dis[i];
			while(now!=1){
				now/=2;
				dat[now]=min(dat[now*2],dat[now*2+1]);
			}
		}
	int X=Q;
	while(Q--){
		long long tmpx,tmpl,tmpr;
		scanf("%lld%lld%lld",&tmpx,&tmpl,&tmpr);
		tmpx--;tmpl--;tmpr--;
		l[tmpx].push_back(tmpl);
		r[tmpx].push_back(tmpr);
		p[tmpx].push_back(X-Q-1);
	}
	dfs2(0,-1);
	for(int i=0;i<X;i++)cout<<ans[i]<<endl;
}