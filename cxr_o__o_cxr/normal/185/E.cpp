//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4,inf=0x3f3f3f3f;
namespace sz{
	int n,t[N<<1];
	inline void clear(int cn){
		n=cn;
		for(int i=1;i<=n;i++)t[i]=-inf;
	}
	inline void add(int x,int v){
		for(;x<=n;x+=x&-x)t[x]=max(t[x],v);
	}
	inline int ask(int x){
		int ret=-inf;
		for(;x;x-=x&-x)ret=max(ret,t[x]);
		return ret;
	}
}
int lim,tot;
namespace seg{
	const int M=2e6+4;
	#define lc ch[p][0]
	#define rc ch[p][1]
	int ch[M][2],t[M];
	void insert(int &p,int l,int r,int x){
		if(p<=lim){
			ch[++tot][0]=ch[p][0];ch[tot][1]=ch[p][1];
			t[tot]=t[p];p=tot;
		}
		t[p]++;
		if(l==r)return;
		int mid=l+r>>1;
		if(x<=mid)insert(lc,l,mid,x);
		else insert(rc,mid+1,r,x);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(!p||(ql<=l&&r<=qr))return t[p];
		int mid=l+r>>1;
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(mid<ql)return query(rc,mid+1,r,ql,qr);
		return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
	}
}
struct poin{
	int x,y,id;
}a[N],b[N],c[N<<1];
int d[N<<1],lx[N],ly[N],rt[N];
inline bool comp_x(const poin &a,const poin &b){
	return a.x==b.x?(a.y==b.y?a.id<b.id:a.y<b.y):a.x<b.x;
}
inline bool comp_v(const poin &a,const poin &b){
	return a.id<b.id;
}
inline bool ask(int l1,int r1,int l2,int r2){
	l1=lower_bound(lx+1,lx+lx[0]+1,l1)-lx;
	r1=upper_bound(lx+1,lx+lx[0]+1,r1)-lx-1;
	l2=lower_bound(ly+1,ly+ly[0]+1,l2)-ly;
	r2=upper_bound(ly+1,ly+ly[0]+1,r2)-ly-1;
	return seg::query(rt[r1],1,ly[0],l2,r2)!=seg::query(rt[l1-1],1,ly[0],l2,r2);
}
inline void findnear(int n){
	sort(c+1,c+n+1,comp_x);
	for(int i=1;i<=n;i++)d[i]=c[i].y;
	sort(d+1,d+n+1);
	int cn=unique(d+1,d+n+1)-d-1;
	sz::clear(cn);
	for(int i=1,r;i<=n;i++){
		r=lower_bound(d+1,d+cn+1,c[i].y)-d;
		if(c[i].id){
			a[c[i].id].id=min(a[c[i].id].id,c[i].x+c[i].y-sz::ask(r));
		}
		else{
			sz::add(r,c[i].x+c[i].y);
		}
	}
}
int n,m;
vector<int>vec[N];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i].x=c[i].x=read();a[i].y=c[i].y=read();
		a[i].id=inf;
		c[i].id=i;
	}
	for(int i=1;i<=m;i++){
		b[i].x=c[i+n].x=read();b[i].y=c[i+n].y=read();
	}
	findnear(n+m);
	for(int i=1;i<=n+m;i++)c[i].x=-c[i].x;
	findnear(n+m);
	for(int i=1;i<=n+m;i++)c[i].y=-c[i].y;
	findnear(n+m);
	for(int i=1;i<=n+m;i++)c[i].x=-c[i].x;
	findnear(n+m);
	// for(int i=1;i<=n;i++)cout<<a[i].id<<" ";
	// puts("");
	for(int i=1,u,v;i<=n;i++){
		u=a[i].x;v=a[i].y;
		a[i].x=u+v;a[i].y=u-v;
	}
	for(int i=1,u,v;i<=m;i++){
		u=b[i].x;v=b[i].y;
		b[i].x=u+v;b[i].y=u-v;
	}
	for(int i=1;i<=m;i++){
		lx[++lx[0]]=b[i].x;
		ly[++ly[0]]=b[i].y;
	}
	lx[++lx[0]]=ly[++ly[0]]=inf;
	lx[++lx[0]]=ly[++ly[0]]=-inf;
	sort(lx+1,lx+lx[0]+1);
	sort(ly+1,ly+ly[0]+1);
	lx[0]=unique(lx+1,lx+lx[0]+1)-lx-1;
	ly[0]=unique(ly+1,ly+ly[0]+1)-ly-1;
	for(int i=1,x;i<=m;i++){
		x=lower_bound(lx+1,lx+lx[0],b[i].x)-lx;
		vec[x].push_back(i);
	}
	for(int i=1,y;i<=lx[0];i++){
		rt[i]=rt[i-1];
		for(auto v:vec[i]){
			y=lower_bound(ly+1,ly+ly[0]+1,b[v].y)-ly;
			seg::insert(rt[i],1,ly[0],y);
		}
		lim=tot;
	}
	sort(a+1,a+n+1,comp_v);
	int l=0,r=inf/2,mid,l1,r1,l2,r2,fl;
	while(l<r){
		mid=l+r>>1;
		l1=l2=-inf/4;
		r1=r2=inf/4;
		fl=0;
		for(int i=n,d;i&&l1<=r1&&l2<=r2;i--){
			d=mid-a[i].id;
			if(d>=0){
				fl|=ask(l1-d,r1+d,l2-d,r2+d);
			}
			l1=max(l1,a[i].x-mid);
			r1=min(r1,a[i].x+mid);
			l2=max(l2,a[i].y-mid);
			r2=min(r2,a[i].y+mid);
		}
		fl|=(l1<=r1&&l2<=r2);
		if(fl)r=mid;
		else l=mid+1;
	}
	cout<<r;
	return (0-0);
}
/*
3 4
-4 1
0 -3
-2 3
-1 -2
2 1
0 -3
-1 3
*/