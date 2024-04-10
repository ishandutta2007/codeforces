// Problem: CF793F Julia the snail
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF793F
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+10;
int n,m,q;int ans[N];
int ls[N];vector<pair<int,int>>Qry[N];
#define fi first
#define se second
//fi: se:
struct node{
	int mx,nxt;
	int tagA,tagB;
	node(int a=-2e9):mx(a),nxt(-2e9),tagA(0),tagB(0){}
	void upd(int x){
		if(x>mx)
			nxt=mx,
			mx=x;
		else if(nxt<x&&x<mx)
			nxt=x;
	}
	void upTag(int A,int B){
		if(mx>=A){
			mx=B;
			if(!tagA)tagA=A;
			tagB=B;
		}
	}
}t[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void up(int x){
	t[x]=node();
	t[x].upd(t[lc].mx);
	t[x].upd(t[lc].nxt);
	t[x].upd(t[rc].mx);
	t[x].upd(t[rc].nxt);
}
void down(int x){
	if(t[x].tagA){
		t[lc].upTag(t[x].tagA,t[x].tagB);
		t[rc].upTag(t[x].tagA,t[x].tagB);
		t[x].tagA=t[x].tagB=0;
	}
}
void build(int x,int l,int r){
	if(l==r){t[x]=node(l);return;}
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(x);
}
void upd(int x,int l,int r,int ql,int qr,int A,int B){
	if(t[x].mx<A||r<ql||qr<l)return;
	if(ql<=l&&r<=qr&&t[x].nxt<A){
		t[x].upTag(A,B);
		return;
	}
	down(x);
	upd(lc,l,mid,ql,qr,A,B);
	upd(rc,mid+1,r,ql,qr,A,B);
	up(x);
}
int qry(int x,int l,int r,int pos){
	if(l==r)return t[x].mx;
	down(x);
	if(pos<=mid)return qry(lc,l,mid,pos);
	else return qry(rc,mid+1,r,pos);
}
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		int l,r;read(l,r);
		ls[r]=l;
	}
	read(q);
	for(int i=1;i<=q;i++){
		int x,y;read(x,y);
		Qry[y].push_back({x,i});
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		if(ls[i])upd(1,1,n,1,ls[i],ls[i],i);
		for(auto [x,id]:Qry[i])
			ans[id]=qry(1,1,n,x);
	}
	for(int i=1;i<=q;i++)
		write(ans[i]),putchar('\n');
}