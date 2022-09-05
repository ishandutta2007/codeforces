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
const int N = 344444;
struct seg{
	int l,r,v;seg(int L=0,int R=0,int V=0){l=L;r=R;v=V;}
	bool operator < (const seg &a)const{return l!=a.l?l<a.l:r<a.r;}
};
int n,k,p[N],del[N];set<seg>Set;vector<seg>a[N];
inline int getinter(int l, int r, int L, int R){return min(r,R)-max(l,L);}
inline void solve(int mid){
	memset(del,0,4*(n+2));
	for(int i=1,j=0,now=0;i<=n;i++){
		rep(k,0,SZ(a[i])-1){
			if(a[i][k].l<=j&&a[i][k].r>=j)now+=a[i][k].v;
			del[a[i][k].l]+=a[i][k].v;del[a[i][k].r+1]-=a[i][k].v;
		}
		while(now+del[j+1]>=mid)now+=del[j+1],j++;p[i]=j;
	}
}
int main() {
	read(n);read(k);Set.insert(seg(1,1e9,0));int mx=0;
	rep(i,1,n){
		int l,r;read(l);read(r);mx=max(mx,r);
		set<seg>::iterator it=Set.lower_bound(seg(l,0,0)),it1;
		if(it!=Set.begin()){it1=it;it1--;if(getinter(l,r,(*it1).l,(*it1).r)>0)it=it1;}
		vector<seg>q;q.pb(seg(l,r,i));
		while(it!=Set.end()&&getinter(l,r,(*it).l,(*it).r)>0){
			a[i].pb(seg((*it).v+1,i,getinter(l,r,(*it).l,(*it).r)));
			if((*it).l<l)q.pb(seg((*it).l,l,(*it).v));
			if(r<(*it).r)q.pb(seg(r,(*it).r,(*it).v));
			it=Set.erase(it);
		}
		rep(i,0,SZ(q)-1)Set.insert(q[i]);
		//rep(j,0,SZ(a[i])-1)printf("%d:[%d,%d] %d\n",i,a[i][j].l,a[i][j].r,a[i][j].v);
	}
	int l=1,r=mx,pos=1;
	while(l<=r){
		int mid=(l+r)>>1;solve(mid);
		ll tot=0;rep(i,1,n)tot+=p[i];
		if(tot>=k)pos=mid,l=mid+1;else r=mid-1;
	}
	solve(pos);ll tot=0,res=0;rep(i,1,n)tot+=p[i];res-=(tot-k)*pos;
	//printf("%d %lld\n",pos,tot);
	memset(del,0,sizeof(del));
	for(ll i=1,j=0,now=0,tot=0;i<=n;i++){
		rep(k,0,SZ(a[i])-1){
			tot+=1LL*max((j-a[i][k].l+1),0LL)*a[i][k].v;
			if(a[i][k].l<=j&&a[i][k].r>=j)now+=a[i][k].v;
			del[a[i][k].l]+=a[i][k].v;del[a[i][k].r+1]-=a[i][k].v;
		}
		while(j<p[i])now+=del[j+1],tot+=now,j++;res+=tot;
	}
	cout<<res;
	return 0;
}