#include<bits/stdc++.h>
#define int long long
#define ls k<<1
#define rs k<<1|1
#define mid ((l+r)>>1)
const int N=200005,P=31;
using namespace std;

int n,m,q;

struct lnb{
	int p[N];
	stack<int> s;
	int ins(int k){
		for(int i=P-1;~i;i--)
			if(k>>i&1){
				if(!p[i]){
					s.push(i),p[i]=k;
					return 1;
				}
				k^=p[i];
			}
		s.push(114514);
		return 0;
	}
	void del(){p[s.top()]=0,s.pop();}
}A;

struct dsu{
	int fa[N],sz[N],ds[N];
	void init(){
		for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	}
	int gf(int k){return k==fa[k]?k:gf(fa[k]);}
	int dp(int k){return k==fa[k]?0:ds[k]^dp(fa[k]);}
	stack<int> s; 
	stack<vector<int>> v;
	bool mrg(int x,int y,int z){
		int fx=gf(x),fy=gf(y);
		int dx=dp(x),dy=dp(y);
		if(fx==fy){
			s.push(1);
			A.ins(dx^dy^z);
		}
		else{
			if(sz[fx]>sz[fy])swap(fx,fy);
			s.push(0);
			fa[fx]=fy,sz[fy]+=sz[fx],ds[fx]=dx^dy^z;
			v.push({fx,fy,sz[fx]});
		}
		return 1; 
	}
	void del(){
		int x=s.top();s.pop();
		if(x==1)
			A.del();
		else{
			auto x=v.top();v.pop();
			fa[x[0]]=x[0],sz[x[1]]-=x[2],ds[x[0]]=0;
		}
	}
	int dis(int x,int y){
		return dp(x)^dp(y);
	}
}T;

map<pair<int,int>,pair<int,int>> a;
pair<int,int> Q[N];
vector<vector<int>> v[N<<2]; 
int res[N];

void psh(int k,int l,int r,int x,int y,int a,int b,int c){
	if(r<x||l>y)return ;
	if(r<=y&&l>=x){
		v[k].push_back({a,b,c});
		return ;
	}
	psh(ls,l,mid,x,y,a,b,c),psh(rs,mid+1,r,x,y,a,b,c);
}
void solve(int k,int l,int r){
	for(auto x:v[k])
		T.mrg(x[0],x[1],x[2]);
	if(l==r){
		if(Q[l].first){
			int ans=T.dis(Q[l].first,Q[l].second);
			for(int i=P-1;~i;i--)
				if(ans>>i&1)
					ans^=A.p[i];
			res[l]=ans;
		}
	}
	else
		solve(ls,l,mid),solve(rs,mid+1,r);
	for(auto x:v[k])
		T.del();
}

void solve(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		a[{x,y}]={1,z};
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int o;cin>>o;
		if(o==1){
			int x,y,z;cin>>x>>y>>z;
			a[{x,y}]={i,z};
		}
		if(o==2){
			int x,y;cin>>x>>y;
			auto p=a[{x,y}];
			psh(1,1,q,p.first,i,x,y,p.second);
			a[{x,y}]={0,0};
		}
		if(o==3){
			int x,y;cin>>x>>y;
			Q[i]={x,y};
		}
	}
	for(auto x:a)
		if(x.second.first)
			psh(1,1,q,x.second.first,q,x.first.first,x.first.second,x.second.second);
	T.init();
	solve(1,1,q); 
	for(int i=1;i<=q;i++)
		if(Q[i].first)
			cout<<res[i]<<endl;
			
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}