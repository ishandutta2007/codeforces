#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005,M=N*30;
struct node{
	int v,p,id;
}x[N];
int rt[N],val[N],lc[M],rc[M],s[M];
map<int,int> cnt;
int n,m,a,b,sz;

void ins(int &o,int l,int r,int x){
	lc[++sz]=lc[o];
	rc[sz]=rc[o];
	s[sz]=s[o];
	o=sz;
	if(l==r){
		s[o]++;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		ins(lc[o],l,mid,x);
	}
	else{
		ins(rc[o],mid+1,r,x);
	}
	s[o]=s[lc[o]]+s[rc[o]];
}

int qry(int o,int l,int r,int x){
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(s[lc[o]]<x){
		return qry(rc[o],mid+1,r,x-s[lc[o]]);
	}
	return qry(lc[o],l,mid,x);
}

int main(){
	read(n);
	rep(i,1,n){
		read(x[i].v);
		val[i]=x[i].v;
		x[i].p=++cnt[x[i].v];
		x[i].id=i;
	}
	sort(x+1,x+n+1,[&](node a,node b){
		return a.v>b.v||a.v==b.v&&a.p<b.p;
	});
	rep(i,1,n){
		rt[i]=rt[i-1];
		ins(rt[i],1,n,x[i].id);
	}
	for(read(m);m;m--){
		read(a),read(b);
		printf("%d\n",val[qry(rt[a],1,n,b)]);
	}
	return 0;
}