#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333, M = 12200000, mx = 1e9;
map<string,int>Map;int num;
int rt[N],rt1[N],lc[M],rc[M],val[M],sz;
inline void ins(int &k, int p, int v, int l, int r){
	val[sz+1]=val[k]+v;lc[sz+1]=lc[k];rc[sz+1]=rc[k];k=++sz;
	if(l==r)return;int mid=(l+r)>>1;
	if(p<=mid)ins(lc[k],p,v,l,mid);else ins(rc[k],p,v,mid+1,r);
}
inline int query(int k, int l, int r, int L, int R){
	if(!k||l==L&&r==R)return val[k];int mid=(L+R)>>1;
	if(r<=mid)return query(lc[k],l,r,L,mid);
	if(l>mid)return query(rc[k],l,r,mid+1,R);
	return query(lc[k],l,mid,L,mid)+query(rc[k],mid+1,r,mid+1,R);
}
int main() {
	int q;read(q);rep(t,1,q){
		char s[22];scanf("%s",s);rt[t]=rt[t-1];rt1[t]=rt1[t-1];
		if(s[0]=='s'){
			string tt;cin>>tt;if(!Map.count(tt))Map[tt]=++num;int k=Map[tt];
			int x;read(x);int a=query(rt[t],k,k,1,q);
			if(a)ins(rt1[t],a,-1,1,mx),ins(rt[t],k,-a,1,q);
			ins(rt1[t],x,1,1,mx);ins(rt[t],k,x,1,q);
		}
		else if(s[0]=='r'){
			string tt;cin>>tt;if(!Map.count(tt))Map[tt]=++num;int k=Map[tt];
			int a=query(rt[t],k,k,1,q);
			if(a)ins(rt1[t],a,-1,1,mx),ins(rt[t],k,-a,1,q);
		}
		else if(s[0]=='q'){
			string tt;cin>>tt;if(!Map.count(tt))Map[tt]=++num;int k=Map[tt];
			int a=query(rt[t],k,k,1,q);
			if(!a)puts("-1");
			else printf("%d\n",1<=a-1?query(rt1[t],1,a-1,1,mx):0);
			fflush(stdout);
		}
		else{
			int x;read(x);rt[t]=rt[t-1-x];rt1[t]=rt1[t-1-x];
		}
	}
	return 0;
}