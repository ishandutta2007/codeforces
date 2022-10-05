#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n):i++)
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

const int N=200005;
struct node{
	int mn,mx;
	set<int> s;
}T[N<<2];
struct chg{
	int l,r,op;
}; vector<chg> q[N];
int a[N],b[N],c[N],d[N],xx[N],yy[N],tag[N];
int n,cx,cy;

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void up(int o){
	T[o].mx=max(*(--T[o].s.end()),max(T[lc].mx,T[rc].mx));
	T[o].mn=max(*(--T[o].s.end()),min(T[lc].mn,T[rc].mn));
	if(T[o].mn>T[o].mx) T[o].mx=-1;
	if(T[o].mx>=1&&tag[T[o].mx]) T[o].mx=-1;
}
void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		if(z>0) T[o].s.insert(z);
		if(z<0) T[o].s.erase(-z);
		if(l==r){
			T[o].mn=T[o].mx=*(--T[o].s.end());
			if(T[o].mx>=1&&tag[T[o].mx]) T[o].mx=-1;
		}
		else up(o);
		return;
	}
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	up(o);
}

void init(){
	read(n);
	rep(i,1,n){
		read(a[i]),read(b[i]),read(c[i]),read(d[i]);
		c[i]--,d[i]--;
		xx[++cx]=a[i],xx[++cx]=c[i]+1;
		yy[++cy]=b[i],yy[++cy]=d[i]+1;
	}
	sort(xx+1,xx+cx+1),cx=unique(xx+1,xx+cx+1)-xx-1;
	sort(yy+1,yy+cy+1),cy=unique(yy+1,yy+cy+1)-yy-1;
	rep(i,1,n){
		a[i]=lower_bound(xx+1,xx+cx+1,a[i])-xx;
		b[i]=lower_bound(yy+1,yy+cy+1,b[i])-yy;
		c[i]=lower_bound(xx+1,xx+cx+1,c[i]+1)-xx-1;
		d[i]=lower_bound(yy+1,yy+cy+1,d[i]+1)-yy-1;
//		printf("# %d %d %d %d\n",a[i],b[i],c[i],d[i]);
	}
}

int main(){
	init();
	rep(i,1,n){
		q[b[i]].pb((chg){a[i],c[i],i});
		q[d[i]+1].pb((chg){a[i],c[i],-i});
	}
	rep(i,1,cx<<2){
		T[i].mn=T[i].mx=-1;
		T[i].s.insert(-1);
	}
	rep(i,1,cy){
		for(auto t:q[i]){
			upd(1,1,cx,t.l,t.r,t.op);
//			printf("upd %d %d %d\n",t.l,t.r,t.op);
		}
		while(T[1].mx>=1){
			int x=T[1].mx; tag[x]=1;
//			printf("## %d\n",x);
			upd(1,1,cx,a[x],c[x],0);
		}
	}
	int ans=1;
	rep(i,1,n) ans+=tag[i];
	cout<<ans<<endl;
	return 0;
}