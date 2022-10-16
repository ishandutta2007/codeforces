#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int n,L,R,ax,ay,val,N,cen,pw;
bool ok;
vector<int>v[100003],g[100003];
bool vis[100003];
inline int findcentroid(int x,int p){
	int sz=1,maxn=0;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]]&&v[x][i]!=p){
			int tmp=findcentroid(v[x][i],x);
			maxn=max(maxn,tmp);sz+=tmp;
		}
	if(maxn<=(N>>1)&&N-sz<=(N>>1))
		cen=x;
	return sz;
}
pair<int,int>dat[262144][2];
int col[100003],dep[100003],sz[100003];
inline void add(int k,int x,int w){
	k+=pw;
	while(k){
		if(dat[k][0].second==-1||col[x]!=col[dat[k][0].second]){
			dat[k][1]=max(dat[k][1],{w,x});
			if(dat[k][0]<dat[k][1])
				swap(dat[k][0],dat[k][1]);
		}else
			dat[k][0]=max(dat[k][0],{w,x});
		k>>=1;
	}
}
inline pair<int,int>query(int _l,int _r,int l,int r,int k,int c){
	if(_l>r||_r<l)
		return {-n,-1};
	if(_l<=l&&r<=_r)
		if(dat[k][0].second==-1||col[dat[k][0].second]!=c)
			return dat[k][0];
		else
			return dat[k][1];
	return max(query(_l,_r,l,l+r>>1,k<<1,c),query(_l,_r,l+r+1>>1,r,k<<1|1,c));
}
inline int DFS(int x,int p,int c,int w){
	sz[x]=1;
	col[x]=c;dep[x]=dep[p]+1;
	add(dep[x],x,w);
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]]&&v[x][i]!=p)
			sz[x]+=DFS(v[x][i],x,c,w+(g[x][i]>=val)-(g[x][i]<val));
	return sz[x];
}
inline void calcans(int x,int p,int w){
	int l=max(0,L-dep[x]),r=min(pw-1,R-dep[x]);
	if(l<=r){
		pair<int,int>tmp=query(l,r,0,pw-1,1,col[x]);
		if(tmp.first+w>=0){
			ok=1;
			ax=x;
			ay=tmp.second;
			return;
		}
	}
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]]&&v[x][i]!=p){
			calcans(v[x][i],x,w+(g[x][i]>=val)-(g[x][i]<val));
			if(ok)return;
		}
}
void dfs(int x,int _sz){
	N=_sz;
	if(N<=L)return;
	findcentroid(x,-1);
	x=cen;
	pw=1;
	while(pw<N)
		pw<<=1;
	for(int i=0;i<(pw<<1);i++)
		dat[i][0]={-n,-1},
		dat[i][1]={-n,-1};
	dep[x]=0;
	col[x]=0;
	add(0,x,0);
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			DFS(v[x][i],x,i+1,(g[x][i]>=val)-(g[x][i]<val));
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			calcans(v[x][i],x,(g[x][i]>=val)-(g[x][i]<val));
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]]){
			if(ok)return;
			dfs(v[x][i],sz[v[x][i]]);
		}
}
bool check(int tmp){
	memset(vis,0,sizeof(vis));
	ok=0;val=tmp;
	dfs(0,n);
	return ok;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>L>>R;
	vector<int>V;
	for(int i=1;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;x--;y--;
		v[x].push_back(y);
		g[x].push_back(z);
		v[y].push_back(x);
		g[y].push_back(z);
		V.push_back(z);
	}sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	int l=0,r=V.size()-1,mid;
	if(V.size()==1)check(V[0]);
	while(l!=r){
		mid=(l+l+r+2)/3;
		if(check(V[mid]))
			l=mid;
		else
			r=mid-1;
	}
	cout<<ax+1<<' '<<ay+1;
}