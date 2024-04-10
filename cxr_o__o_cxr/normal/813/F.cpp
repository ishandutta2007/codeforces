#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define lc (p<<1)
#define rc (p<<1|1)
const int N=1e5+4;
vector<int>t[N<<2];
int n,Q,top,uu[N],vv[N],fa[N],st[N],d[N],siz[N],vis[N];
void modify(int p,int l,int r,int ql,int qr,int i){
	if(ql<=l&&r<=qr){t[p].push_back(i);return;} 
	int mid=l+r>>1;
	if(ql<=mid)modify(lc,l,mid,ql,qr,i);
	if(mid<qr)modify(rc,mid+1,r,ql,qr,i);
}
int find(int x,int &dis){
	if(x==fa[x]){
		dis^=d[x];//
		return x;
	}
	dis^=d[x];
	return find(fa[x],dis);
}
inline void back(int cou){
	while(cou--){
		siz[fa[st[top]]]-=siz[st[top]];
		fa[st[top]]=st[top];d[st[top]]=0;
		top--;
	}
}
void solve(int p,int l,int r){
	int cou=0,u,v,du,dv;
	for(auto i:t[p]){
		du=dv=0;//
		u=find(uu[i],du);v=find(vv[i],dv);
		if(u==v){
			if(!(du^dv)){
				for(int j=l;j<=r;j++)puts("NO");
				back(cou);return;
			}
			continue;
		}
		if(siz[u]<siz[v])u^=v^=u^=v;
		st[++top]=v;
		fa[v]=u;
		siz[u]+=siz[v];
		d[v]=dv^du^1;//
		cou++;
	}
	if(l==r){
		puts("YES");
		back(cou);return;
	}
	int mid=l+r>>1;
	solve(lc,l,mid);
	solve(rc,mid+1,r);
	back(cou);
}
map<pair<int,int>,int>mp;
int main(){
	n=read();Q=read();
	for(int i=1,t;i<=Q;i++){
		uu[i]=read();vv[i]=read();
		if(uu[i]>vv[i])swap(uu[i],vv[i]);
		pair<int,int> tmp=make_pair(uu[i],vv[i]);
		if(mp[tmp]){
			t=mp[tmp];
			modify(1,1,Q,t,i-1,t);
			vis[t]=0;
			mp[tmp]=0;
		}
		else{mp[tmp]=i;vis[i]=1;}
	}
	for(int i=1;i<=Q;i++)if(vis[i])
		modify(1,1,Q,i,Q,i);
	for(int i=1;i<=n;i++){fa[i]=i;siz[i]=1;}
	solve(1,1,Q);
	return (0-0);
}