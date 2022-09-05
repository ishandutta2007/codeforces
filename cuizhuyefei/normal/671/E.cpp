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
const int N = 126666;const ll inf=1e15;
ll n,k,w[N],g[N],sta[N],top;Vi era[N];
struct Tree{
	ll mna[N<<2],mxb[N<<2],lzy[N<<2],val[N<<2];bool leaf[N<<2];
	inline void pushadd(int k, ll x){
		lzy[k]+=x;mxb[k]+=x;
	}
	inline void pushdown(int k){
		if(lzy[k]){
			pushadd(k<<1,lzy[k]);pushadd(k<<1|1,lzy[k]);lzy[k]=0;
		}
	}
	ll qry(int k, ll x){
		if(leaf[k])return mna[k]+max(mxb[k],x);pushdown(k);
		if(x>mxb[k<<1|1])return min(qry(k<<1,x),mna[k<<1|1]+x);
		return min(val[k],qry(k<<1|1,x));
	}
	inline void upd(int k){
		mna[k]=min(mna[k<<1],mna[k<<1|1]);
		mxb[k]=max(mxb[k<<1],mxb[k<<1|1]);
		if(leaf[k])val[k]=mna[k]+mxb[k];else val[k]=qry(k<<1,mxb[k<<1|1]);
	}
	void modify(int k, int l, int r, ll x, int L, int R){assert(l>=L&&r<=R&&l<=r);
	//	if(k==1&&r<=3)cerr<<"modify "<<l<<' '<<r<<' '<<x<<endl;
		if(l==L&&r==R){pushadd(k,x);return;}
		int mid=(L+R)>>1;pushdown(k);
		if(r<=mid)modify(k<<1,l,r,x,L,mid);
		else if(l>mid)modify(k<<1|1,l,r,x,mid+1,R);
		else modify(k<<1,l,mid,x,L,mid),modify(k<<1|1,mid+1,r,x,mid+1,R);
		upd(k);
	}
	void erasea(int k, int p, int L, int R){assert(p>=L&&p<=R);
		if(p==L&&p==R){mna[k]=inf;return;}
		int mid=(L+R)>>1;pushdown(k);
		if(p<=mid)erasea(k<<1,p,L,mid);else erasea(k<<1|1,p,mid+1,R);
		upd(k);
	}
	int node[N],zuo[N],you[N],sz;
	void qry(int k, int l, int r, ll x, ll lim, int L, int R){assert(l>=L&&r<=R&&l<=r);
		if(l==L&&r==R){
			node[++sz]=k;zuo[sz]=l;you[sz]=r;return;
		}
		int mid=(L+R)>>1;pushdown(k);
		if(r<=mid)qry(k<<1,l,r,x,lim,L,mid);
		else if(l>mid)qry(k<<1|1,l,r,x,lim,mid+1,R);
		else qry(k<<1,l,mid,x,lim,L,mid),qry(k<<1|1,mid+1,r,x,lim,mid+1,R);
	}
	ll qryb(int k, int l, int r, int L, int R){assert(l>=L&&r<=R&&l<=r);
		if(l==L&&r==R)return mxb[k];
		int mid=(L+R)>>1;pushdown(k);
		if(r<=mid)return qryb(k<<1,l,r,L,mid);
		else if(l>mid)return qryb(k<<1|1,l,r,mid+1,R);
		return max(qryb(k<<1,l,mid,L,mid),qryb(k<<1|1,mid+1,r,mid+1,R));
	}
	int getans(ll x, ll lim, int Zuo, int cur){
		if(Zuo>cur)return -1;assert(Zuo<=cur);
		sz=0;qry(1,Zuo,cur,x,lim,0,n+1);static ll hz[N];
		hz[sz+1]=x;per(i,sz,1)hz[i]=max(hz[i+1],mxb[node[i]]);
		rep(i,1,sz)if(qry(node[i],hz[i+1])<=lim){
			int k=node[i],l=zuo[i],r=you[i];x=hz[i+1];
			while(l<r){
				pushdown(k);int mid=(l+r)>>1;
				if(qry(k<<1,max(x,mxb[k<<1|1]))<=lim)x=max(x,mxb[k<<1|1]),k=k<<1,r=mid;
				else k=k<<1|1,l=mid+1;
			}
			return l;
		}//else if(cur==2)cerr<<"zibile "<<' '<<mna[node[i]]<<' '<<hz[i+1]<<' '<<qry(node[i],hz[i+1])<<' '<<lim<<endl;
		return -1;
	}
	void build(int k, int l, int r){
		if(l==r){
			leaf[k]=1;
			mna[k]=l-1>=0?g[l-1]-w[l-1]:0;mxb[k]=w[l]-g[l];
			return;
		}
		int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		upd(k);
	}
}yzr;
ll L[N],R[N],v[N][17];
int main() {
	read(n);read(k);
	rep(i,1,n-1)read(w[i]),w[i]+=w[i-1];w[n]=w[n+1]=w[n-1];
	rep(i,1,n)read(g[i]),g[i]+=g[i-1];g[n+1]=g[n];
	
	rep(i,1,n)v[i][0]=w[i]-g[i];
	rep(j,1,16)rep(i,1,n-(1<<j)+1)v[i][j]=max(v[i][j-1],v[i+(1<<j-1)][j-1]);
	rep(l,1,n){
		int p=l-1;
		per(i,16,0)if(p+(1<<i)<=n&&v[p+1][i]<=k+w[l-1]-g[l-1])p+=1<<i;
		R[l]=p+1;
		if(R[l]<=n)assert(w[R[l]]-g[R[l]]>k+w[l-1]-g[l-1]);
	}
	
	rep(i,1,n)v[i][0]=(i-2>=0?-w[i-2]:0)+g[i-1];
	rep(j,1,16)rep(i,1,n-(1<<j)+1)v[i][j]=max(v[i][j-1],v[i+(1<<j-1)][j-1]);
	rep(r,1,n){
		int p=r+1;
		per(i,16,0)if(p-(1<<i)>=1&&v[p-(1<<i)][i]<=k-w[r-1]+g[r])p-=1<<i;
		L[r]=p-1;
		if(L[r]>=1)assert(-(L[r]-2>=0?w[L[r]-2]:0)+g[L[r]-1]>k-w[r-1]+g[r]);
	}
	
	rep(i,1,n)era[R[i]+1].pb(i);
	yzr.build(1,0,n+1);int res=1;
	
//	rep(i,1,n)cerr<<i<<' '<<L[i]<<' '<<R[i]<<endl;
//	cerr<<"ori "<<yzr.qryb(1,3,3,0,n+1)<<endl;
//	rep(i,1,n)cerr<<yzr.qryb(1,i,i,0,n+1)<<endl;
	
	rep(r,1,n){
		if(r){
			ll x=g[r-1]-(r-2>=0?w[r-2]:0);
			while(top&&g[sta[top]-1]-(sta[top]-2>=0?w[sta[top]-2]:0)<x){
				yzr.modify(1,sta[top-1]+1-1,sta[top]-1,x-(g[sta[top]-1]-(sta[top]-2>=0?w[sta[top]-2]:0)),0,n+1);top--;
			}
			sta[++top]=r;yzr.modify(1,r-1,r-1,x,0,n+1);
		}
		rep(i,0,SZ(era[r])-1)yzr.erasea(1,era[r][i],0,n+1);
		int l=yzr.getans(-inf,k-w[r-1]+g[r],max((int)L[r],1),r-1);if(l>=0)umax(res,r-l+1);//,cerr<<l<<' '<<r<<endl;
		/*if(r==3){
			rep(i,1,r)cerr<<"qwq "<<yzr.qryb(1,i,i,0,n+1)<<endl;
			cerr<<"qwq "<<yzr.qryb(1,1,r,0,n+1)<<endl;
			cerr<<"qwq "<<k-w[r-1]+g[r]<<endl;
		}*/
	}
	cout<<res;
	return 0;
}