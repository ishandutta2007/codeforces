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

const int N=500005;
namespace lct{
	int fa[N],t[N][2],sz[N],isz[N];
	int rev[N],val[N],mx[N],cur[N];
	int isr(int x){
		return t[fa[x]][0]!=x&&t[fa[x]][1]!=x;
	}
	void up(int x){
		sz[x]=sz[t[x][0]]+(!val[x])+sz[t[x][1]]+isz[x];
		mx[x]=val[x],cur[x]=x;
		REP(k,2)if(mx[t[x][k]]>mx[x])
			mx[x]=mx[t[x][k]],cur[x]=cur[t[x][k]];
	}
	void Rev(int x){
		if(!x)return;swap(t[x][0],t[x][1]),rev[x]^=1;
	}
	void down(int x){
		if(rev[x])Rev(t[x][0]),Rev(t[x][1]),rev[x]=0;
	}
	#define B(x) (t[fa[x]][1]==x)
	void rot(int x){
		int y=fa[x],f=B(x),z=fa[y];
		fa[t[y][f]=t[x][f^1]]=y;
		if(!isr(y))t[z][B(y)]=x;fa[x]=z;
		fa[t[x][f^1]=y]=x,up(y),up(x);
	}
	void push(int x){
		if(!isr(x))push(fa[x]);down(x);
	}
	void spl(int x){
		push(x);
		for(;!isr(x);rot(x))
			if(!isr(fa[x]))rot(B(x)^B(fa[x])?x:fa[x]);
	}
	void access(int x){
		for(int y=0;x;y=x,x=fa[x])
			spl(x),isz[x]+=sz[t[x][1]],isz[x]-=sz[t[x][1]=y],up(x);
	}
	void evert(int x){
		access(x),spl(x),Rev(x);
	}
	void link(int x,int y){
		evert(x),access(y),spl(y);
		fa[x]=y,isz[y]+=sz[x],up(y);
	}
	void cut(int x,int y){
		evert(x),access(y),spl(y);
		t[y][0]=fa[x]=0,up(y);
	}
	int getrt(int x){
		access(x),spl(x);
		for(;t[x][0];x=t[x][0]);
		return x;
	}
	int qry(int x,int y){
		evert(x),access(y),spl(y);
		return cur[y];
	}
	int chk(int x,int y){
		evert(x),access(y),spl(y);
		return sz[x]%2==0;
	}
}
int a[N],b[N],c[N];
int n,m,tot;
set<pii> s;

void Link(int k){
	lct::link(a[k],n+k);
	lct::link(b[k],n+k);
	s.insert(mp(c[k],k));
}
void Cut(int k){
	lct::cut(a[k],n+k);
	lct::cut(a[k],n+k);
	s.erase(mp(c[k],k));
}

int main(){
	read(n),read(m),tot=n;
	rep(i,1,m){
		read(a[i]),read(b[i]),read(c[i]);
		lct::val[n+i]=c[i];
		if(lct::getrt(a[i])!=lct::getrt(b[i])){
			tot-=!lct::chk(a[i],a[i]);
			tot-=!lct::chk(b[i],b[i]);
			Link(i);
			tot+=!lct::chk(a[i],a[i]);
		}
		else{
			int k=lct::qry(a[i],b[i])-n;
			if(c[i]<c[k])Cut(k),Link(i);
		}
		if(tot){
			puts("-1");
			continue;
		}
		while(s.size()){
			int k=(--s.end())->se;
			if(!lct::chk(a[k],b[k]))break;
			Cut(k);
		}
		printf("%d\n",(--s.end())->fi);
	}
	return 0;
}