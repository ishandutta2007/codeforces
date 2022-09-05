#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();}
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 100009, M = 263, T = 384; //???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????T = 384!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int n,m,a[N];
int NXT[N]; //the total
int bg[M],ed[M]; //begin/end
struct Block {
	int head[N],tail[N],size[N]; //
	int nxt[N],pre[N],hd; //
	int offset,l,r; // don't forget offset!!!!!!!
	inline void insert(int p, int v) { //originally
		if (!size[v]) {size[v]++; head[v]=tail[v]=p; nxt[v]=hd; pre[hd]=v; hd=v;}
		else {
			size[v]++; NXT[p]=head[v]; head[v]=p;
		}
	}
	inline void insert(int p) { //link
		nxt[p]=hd; pre[hd]=p; hd=p;
	}
	inline void erase(int p) {
		if (p==hd) {hd=nxt[p]; pre[hd]=nxt[p]=0; return;}
		nxt[pre[p]]=nxt[p]; pre[nxt[p]]=pre[p];
		nxt[p]=pre[p]=0;
	}
}s[M];
inline void blo_modify(int k, int v) { //offset = l - 1
	int &l=s[k].l, &r=s[k].r; int ost=s[k].offset; v+=ost;
	if (v>=r) return;
	if (v>=(r+l)/2) {
		rep(i,v+1,r) {
			int j=i-v+ost; if (!s[k].size[i] && !s[k].size[j]) continue;
			if (s[k].size[i]) s[k].erase(i); if (!s[k].size[j]) s[k].insert(j);
			s[k].size[j]+=s[k].size[i]; s[k].size[i]=0;		
			if (!s[k].tail[j]) {
				int &V=s[k].head[i]; s[k].head[j]=V; V=0;
				int &V1=s[k].tail[i]; s[k].tail[j]=V1; V1=0;
			}
			else {
				int a=s[k].tail[j],b=s[k].head[i]; NXT[a]=b;
				if (s[k].tail[i]) s[k].tail[j]=s[k].tail[i]; s[k].head[i]=s[k].tail[i]=0;
			}
		}
		r=v;
	}
	else {
		rep(i,l,v) {
			int j=i+v-ost; if (!s[k].size[i] && !s[k].size[j]) continue;
			if (s[k].size[i]) s[k].erase(i); if (!s[k].size[j] && s[k].size[i]) s[k].insert(j);
			s[k].size[j]+=s[k].size[i]; s[k].size[i]=0;		
			if (!s[k].tail[j]) {
				int &V=s[k].head[i]; s[k].head[j]=V; V=0;
				int &V1=s[k].tail[i]; s[k].tail[j]=V1; V1=0;
			}
			else {
				int a=s[k].tail[j],b=s[k].head[i]; NXT[a]=b;
				if (s[k].tail[i]) s[k].tail[j]=s[k].tail[i]; s[k].head[i]=s[k].tail[i]=0;
			}
		}
		l=v+1; s[k].offset=v; //???
	}
}
Pii rec[N];
inline void modify(int k, int l, int r, int v) {
	int size=0;
	for (int i=s[k].hd; i!=0;) {
	int Next=s[k].nxt[i];
	if (i-s[k].offset>v && s[k].size[i]>0) { //real!!!!!!
		int ost=s[k].offset; int pre=0;
		for (int j=s[k].head[i]; j!=0;) {
			int next=NXT[j];
			if (j>=l && j<=r) {
				if (j==s[k].head[i]) {s[k].head[i]=NXT[j];}
				else if (j==s[k].tail[i]) {s[k].tail[i]=pre; NXT[pre]=0;}
				else NXT[pre]=NXT[j];
				s[k].size[i]--; if (!s[k].size[i]) s[k].erase(i);
				rec[size++]=Pii(j,i-v);
			} else pre=j;
			j=next;
		}
		if (!s[k].size[i]) {s[k].head[i]=s[k].tail[i]=0;}
	}
	i=Next;
	}
	while (size--) {
		int j=rec[size].first,v=rec[size].second;
		NXT[j]=s[k].head[v]; s[k].head[v]=j;
		if (!s[k].size[v]) s[k].tail[v]=j;
		if (!s[k].size[v]) s[k].insert(v); s[k].size[v]++;
	}
}
inline int blo_query(int k, int v) {
	if (v+s[k].offset>s[k].r) return 0; //2n
	return s[k].size[v+s[k].offset];
}
inline int query(int k, int l, int r, int v) {
	int res=0; if (v+s[k].offset>s[k].r) return 0;  //2n
	for (int i=s[k].head[v+s[k].offset]; i!=0; i=NXT[i]) {
		res+=(i>=l && i<=r);
	}
	return res;
}
inline void Modify(int l, int r, int v) {
	int lx=l/T,rx=r/T; if (lx==rx) {modify(lx,l,r,v); return;}
	modify(lx,l,ed[lx],v); modify(rx,bg[rx],r,v);
	rep(i,lx+1,rx-1) blo_modify(i,v);
}
inline int Query(int l, int r, int v) {
	int lx=l/T,rx=r/T,res=0; if (lx==rx) return query(lx,l,r,v);
	res=query(lx,l,ed[lx],v); res+=query(rx,bg[rx],r,v);
	rep(i,lx+1,rx-1) res+=blo_query(i,v);
	return res;
}
int main() {
//	freopen("1.in","r",stdin);
//	freopen("my.out","w",stdout);
	read(n); read(m); rep(i,0,M-1) bg[i]=n;
	rep(i,1,n) {
		read(a[i]); s[i/T].insert(i,a[i]); bg[i/T]=min(bg[i/T],i); ed[i/T]=max(ed[i/T],i);
		s[i/T].l=1; s[i/T].r=max(s[i/T].r,a[i]);
	}
	while (m--) {
		int op,l,r,x; read(op); read(l); read(r); read(x);
		if (op==1) Modify(l,r,x);
		else printf("%d\n",Query(l,r,x));
	}
	return 0;
}
/*
1.
2.clearhead
3.offset offset
*/