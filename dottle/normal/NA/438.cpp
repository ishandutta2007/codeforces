#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mid (l+r>>1)
const int N=200005;
using namespace std;

int n,q;
string s[N];

struct edge{
	int to,nx;
}e[N];int hd[N],_S;
void add(int fr,int to){
	e[++_S]=(edge){to,hd[fr]},hd[fr]=_S;
}
#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)

int L[N<<5],R[N<<5],S[N<<5],T[N],c;
int updt(int pr,int l,int r,int x,int p){
	int k=++c;
	S[k]=S[pr]+p,L[k]=L[pr],R[k]=R[pr];
	if(l^r)
		if(x<=mid)L[k]=updt(L[pr],l,mid,x,p);
		else R[k]=updt(R[pr],mid+1,r,x,p);
	return k;
}
int qry(int k,int l,int r,int x,int y){
	if(!k||r<x||l>y)return 0;
	if(r<=y&&l>=x)return S[k];
	return qry(L[k],l,mid,x,y)+qry(R[k],mid+1,r,x,y);
}

struct AC{
	int sn[26][N],cnt,fa[N],ed[N];
	vector<int> f[N];
	void insert(string&s,int i){
		int nw=0;
		for(auto x:s){
			if(!sn[x-'a'][nw])sn[x-'a'][nw]=++cnt;
			nw=sn[x-'a'][nw];
			f[nw].push_back(i);
		}
		ed[i]=nw;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<26;i++)
			if(sn[i][0])q.push(sn[i][0]);
		while(q.size()){
			int nw=q.front();q.pop();
			for(int i=0;i<26;i++){
				int&v=sn[i][nw];
				if(v) fa[v]=sn[i][fa[nw]],q.push(v);
				else v=sn[i][fa[nw]];
			}
		}
	}
}A;

int sg[N],bc[N],cnt,sz[N];
void dfs(int k,int fa){
	sg[k]=++cnt,bc[cnt]=k,sz[k]=1;
	fore(k){
		dfs(_to,k),sz[k]+=sz[_to];
	}
}

void build(){
	for(int i=1;i<=cnt;i++){
		T[i]=T[i-1];
		for(auto x:A.f[bc[i]])
			T[i]=updt(T[i],1,n,x,1);
	}
}

void solve(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i],A.insert(s[i],i);
	A.build();
	for(int i=1;i<=A.cnt;i++)
		add(A.fa[i],i);
	dfs(0,-1);
	build();
	for(int i=1;i<=q;i++){
		int x,y,z;cin>>x>>y>>z;
		int p=A.ed[z];
		cout<<qry(T[sg[p]+sz[p]-1],1,n,x,y)-qry(T[sg[p]-1],1,n,x,y)<<'\n';
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}