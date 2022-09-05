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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int inf = 0x3f3f3f3f, N = 6000005;
set<Pii>Set;
ll sum[N],qz[N];int lc[N],rc[N],lzy[N],tot=1;
void init(int k, int v, int L, int R){
	lzy[k]=v;sum[k]=1LL*v*(R-L+1);qz[k]=v>=0?0:sum[k];
}
void upd(int k){
	sum[k]=sum[lc[k]]+sum[rc[k]];
	qz[k]=min(qz[lc[k]],sum[lc[k]]+qz[rc[k]]);
}
void pd(int k, int l, int r){
	if(lzy[k]==inf)return;int mid=(l+r)>>1;
	if(!lc[k])lc[k]=++tot;init(lc[k],lzy[k],l,mid);
	if(!rc[k])rc[k]=++tot;init(rc[k],lzy[k],mid+1,r);
	lzy[k]=inf;
}
void modify(int &k, int l, int r, int v, int L, int R){
	if(!k)k=++tot;
	if(l==L&&r==R){
		init(k,v,L,R);//lzy[k]=v;sum[k]=1LL*v*(R-L+1);qz[k]=v>=0?0:sum[k];
		return;
	}
	pd(k,L,R);
	int mid=(L+R)>>1;
	if(r<=mid)modify(lc[k],l,r,v,L,mid);
	else if(l>mid)modify(rc[k],l,r,v,mid+1,R);
	else modify(lc[k],l,mid,v,L,mid),modify(rc[k],mid+1,r,v,mid+1,R);
	upd(k);
}
ll querysum(int k, int l, int r, int L, int R){
	if(!k)return 0;if(l==L&&r==R)return sum[k];
	int mid=(L+R)>>1;
	pd(k,L,R);
	if(r<=mid)return querysum(lc[k],l,r,L,mid);
	if(l>mid)return querysum(rc[k],l,r,mid+1,R);
	return querysum(lc[k],l,mid,L,mid)+querysum(rc[k],mid+1,r,mid+1,R);
}
//bool debug;
int query(int k, int l, int r, ll &v, int L, int R){//<=v
	if(!k)return -1;assert(l>=L&&r<=R);
//	if(debug)printf("query %d %d %d %lld %d %d\n",k,l,r,v,L,R);
	if(l==L&&r==R){
		if(qz[k]>v){v-=sum[k];return -1;}//WA!!!!
		if(L==R)return L;
		int mid=(L+R)>>1;pd(k,L,R);//WA
		if(qz[lc[k]]<=v)return query(lc[k],l,mid,v,L,mid);
		v-=sum[lc[k]];return query(rc[k],mid+1,r,v,mid+1,R);
	}
	int mid=(L+R)>>1;
	pd(k,L,R);
	if(r<=mid)return query(lc[k],l,r,v,L,mid);
	if(l>mid)return query(rc[k],l,r,v,mid+1,R);
	int tmp=query(lc[k],l,mid,v,L,mid);if(tmp>=0)return tmp;
//	printf("lc %d %lld\n",k,sum[lc[k]]);
	return query(rc[k],mid+1,r,v,mid+1,R);
}
/*inline int query(int l, int r, ll v){//<=-v
	int rt=1;Vi a;getdot(rt,l,r,1,inf,a);
	rep(i,0,SZ(a)-1)if(qz[a[i]]<=v){
		
	}else v-=sum[a[i]];
	return -1;
}*/
int main() {//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	memset(lzy,inf,sizeof(lzy));qz[0]=1e18;
	int q;read(q);Set.insert(Pii(1,0));Set.insert(Pii(inf,0));
	int rt=1;
	while(q--){
		int op;read(op);
		if(op==1){
			int t,s;read(t);read(s);
		//	set<Pii>::iterator it=Set.lower_bound(Pii(t,-inf));
		//	if((*it).fi==t){Set.erase(it);}
			Pii tmp=*Set.upper_bound(Pii(t,inf));
			modify(rt,t,tmp.fi-1,s,1,inf);Set.insert(Pii(t,s));
		}
		else if(op==2){
			int t;read(t);Set.erase(Set.lower_bound(Pii(t,-inf)));//-1 is not small
			set<Pii>::iterator it=Set.upper_bound(Pii(t,inf));
			Pii tmp=*it;it--;int s=(*it).se;//printf("<%d %d %d>\n",t,tmp.fi-1,s);
			modify(rt,t,tmp.fi-1,s,1,inf);
		}
		else{
			int l,r,v;read(l);read(r);read(v);
			if(l==r){
				if(!v)printf("%d\n",l);else puts("-1");
				continue;
			}
			set<Pii>::iterator it=Set.lower_bound(Pii(l,-inf));int pos=(*it).fi;
			it--;int pos0=(*it).fi;if(pos0<=pos-1)modify(rt,pos0,pos-1,0,1,inf);
		//	if(l==24&&r==36)debug=1;
			ll V=-v;int res=query(rt,l,r-1,V,1,inf);
		//	int res=query(l,r-1,-v);
			/*if(l==24&&r==36){
				return 0;
				for(set<Pii>::iterator it=Set.begin();it!=Set.end();it++){
					printf("<%d %d>\n",(*it).fi,(*it).se);
				}
				printf("qaq %d %d\n",pos0,pos-1);
				printf("find %d %lld %lld\n",res,l<=res-1?querysum(rt,l,res-1,1,inf):0,querysum(rt,l,res,1,inf));
				rep(i,l,r)printf("%d:%lld\n",i,querysum(rt,l,i,1,inf));
			}*/
			if(res<0)printf("-1\n");
			else{
				ll a=l<=res-1?querysum(rt,l,res-1,1,inf):0,b=querysum(rt,l,res,1,inf);
				//a(res) -v b(res+1)
				assert(res+(a==b?0:1.0*(-v-a)/(b-a))<=res+1);
				printf("%.6lf\n",res+(a==b?0:1.0*(-v-a)/(b-a)));
			//	printf("%d %lld %lld\n",res,a,b);
			}
			if(pos0<=pos-1)modify(rt,pos0,pos-1,(*it).se,1,inf);
		}
	}
	return 0;
}