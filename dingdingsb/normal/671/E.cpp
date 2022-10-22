#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define int ll
const int inf=1e16;
const int N=1e5+100;
int n,k,w[N],g[N],a[N],b[N];
struct SGT{
	int mn1[N<<2],mn2[N<<2],lans[N<<2],tag[N<<2];
	void pushtag(int x,int tg){
		mn1[x]+=tg;
		lans[x]-=tg;
		tag[x]+=tg;
	}
	void pushdown(int x){
		if(tag[x]){
			pushtag(lc,tag[x]);
			pushtag(rc,tag[x]);
			tag[x]=0;
		}
	}
	int calc(int x,int l,int r,int sufmn){
		if(l==r)return mn2[x]-min(mn1[x],sufmn);
		pushdown(x);
		if(mn1[rc]<=sufmn)
			//lcrc
			return min(lans[x],calc(rc,mid+1,r,sufmn));
		else
			//lc sufmn
			//rc mn2  sufmn 
			return min(calc(lc,l,mid,sufmn),mn2[rc]-sufmn);
	}
	void pushup(int x,int l,int r){
		mn1[x]=min(mn1[lc],mn1[rc]);
		mn2[x]=min(mn2[lc],mn2[rc]);
		lans[x]=calc(lc,l,mid,mn1[rc]);
	}
	void build(int x,int l,int r){
		if(l==r){
			mn1[x]=a[l];
			mn2[x]=a[l-1];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x,l,r);
	}
	void add(int x,int l,int r,int ql,int qr,int val){
		//
		if(ql<=l&&r<=qr)return pushtag(x,val);
		if(r<ql||qr<l)return;
		pushdown(x);
		add(lc,l,mid,ql,qr,val);
		add(rc,mid+1,r,ql,qr,val);
		pushup(x,l,r);
	}
	int find_full(int x,int l,int r,int sufmn,int val){
		//
		if(l==r)return l;
		pushdown(x);
		if(calc(lc,l,mid,min(sufmn,mn1[rc]))<=val)
			return find_full(lc,l,mid,min(sufmn,mn1[rc]),val);
		else return find_full(rc,mid+1,r,sufmn,val);
	}
	int find(int x,int l,int r,int ql,int qr,int sufmn,int val){
		//
		if(ql<=l&&r<=qr){
			if(calc(x,l,r,sufmn)<=val)return find_full(x,l,r,sufmn,val);
			else return inf;
		}
		if(r<ql||qr<l)return inf;
		pushdown(x);
		int res=find(lc,l,mid,ql,qr,min(sufmn,mn1[rc]),val);
		if(res!=inf)return res;
		return find(rc,mid+1,r,ql,qr,sufmn,val);
	}
}T;
int top,s[N],sum[N];
int solve(int p,int r){
	if(s[p-1]+1>r-1)return 0;
	ll Sum=sum[top-1]-sum[p-1];
	T.add(1,1,n,r,n,inf);
	T.add(1,1,n,s[p-1]+1,r-1,-sum[p-1]);
	int res=T.find(1,1,n,s[p-1]+1,r-1,inf,k-Sum);
	T.add(1,1,n,r,n,-inf);
	T.add(1,1,n,s[p-1]+1,r-1,sum[p-1]);
	return r-res+1;
}
signed main(){
	read(n,k);
	for(int i=1;i< n;i++)read(w[i]);
	for(int i=1;i<=n;i++)read(g[i]);
	for(int i=1;i< n;i++)a[i]=a[i-1]+g[i]-w[i];
	for(int i=1;i<=n;i++)b[i]=b[i-1]+g[i]-w[i-1];
	T.build(1,1,n);
	int res=1;
	for(int i=1;i<=n;i++){
		while(top&&b[s[top]]<=b[i]){
			top--;
			if(top)T.add(1,1,n,s[top]+1,s[top+1],-sum[top]);
		}
		s[++top]=i;
		if(top>1){
			sum[top-1]=sum[top-2]+b[s[top-1]]-b[i];//s[top-1]+1
			T.add(1,1,n,s[top-1]+1,i,sum[top-1]);
		}
		int l=1,r=top,ans=1;
		while(l<=r){
			if(sum[top-1]-sum[mid-1]<=k)
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		chkmx(res,solve(ans,i));
	}
	write(res);
}