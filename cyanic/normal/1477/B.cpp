#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=1000005;
int T[N<<2],cov[N<<2],l[N],r[N],n,Q;
char s[N],t[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void build(int o,int l,int r){
	cov[o]=-1;
	if(l==r){
		T[o]=t[l]-'0';
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	T[o]=T[lc]+T[rc];
}
void app(int o,int l,int r,int x){
	T[o]=(r-l+1)*x,cov[o]=x;
}
void down(int o,int l,int r){
	if(cov[o]!=-1){
		app(lc,l,mid,cov[o]);
		app(rc,mid+1,r,cov[o]);
		cov[o]=-1;
	}
}
void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		app(o,l,r,z);
		return;
	}
	down(o,l,r);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	T[o]=T[lc]+T[rc];
}
int qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r) return T[o];
	down(o,l,r);
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	return qry(lc,l,mid,x,mid)+qry(rc,mid+1,r,mid+1,y);
}
int chk(int o,int l,int r){
	if(l==r) return T[o]==s[l]-'0';
	down(o,l,r);
	return chk(lc,l,mid)&&chk(rc,mid+1,r);
}

void rmain(){
	read(n),read(Q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	build(1,1,n);
	rep(i,1,Q){
		read(l[i]),read(r[i]);
	}
	per(i,Q,1){
		int ret=qry(1,1,n,l[i],r[i]);
		if(ret*2==r[i]-l[i]+1){
			puts("NO");
			return;
		}
		if(ret*2<r[i]-l[i]+1){
			upd(1,1,n,l[i],r[i],0);
		}
		else{
			upd(1,1,n,l[i],r[i],1);
		}
	}
	puts(chk(1,1,n)?"YES":"NO");
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}