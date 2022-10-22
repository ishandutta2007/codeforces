#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=4e4+100,K=110;
const int inf=0x3f3f3f3f;
int n,k,a[N],lst[N],dp[N][K];
struct SGT{
	int mn[N<<2],tag[N<<2];
	void pushdown(int x){
		mn[lc]+=tag[x];
		tag[lc]+=tag[x];
		mn[rc]+=tag[x];
		tag[rc]+=tag[x];
		tag[x]=0;
	}
	void pushup(int x){
		mn[x]=min(mn[lc],mn[rc]);
	}
	void build(int x,int l,int r){
		mn[x]=inf;tag[x]=0;
		if(l==r)return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void upd(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr){
			mn[x]+=val;
			tag[x]+=val;
			return;
		}
		if(r<ql||qr<l)return;
		pushdown(x);
		upd(lc,l,mid,ql,qr,val);
		upd(rc,mid+1,r,ql,qr,val);
		pushup(x);
	}
	void mdf(int x,int l,int r,int pos,int val){
		if(l==r){
			mn[x]=val;tag[x]=0;
			return;
		}
		pushdown(x);
		if(pos<=mid)mdf(lc,l,mid,pos,val);
		else mdf(rc,mid+1,r,pos,val);
		pushup(x);
	}
}T[K];
signed main(){
	memset(dp,0x3f,sizeof dp);
	read(n,k);
	for(int i=1;i<=n;i++)read(a[i]);
	dp[0][0]=0;
	for(int i=1;i<=k;i++)T[i].build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k&&j<=i;j++){
			T[j].mdf(1,1,n,i,dp[i-1][j-1]);
			if(lst[a[i]])
				T[j].upd(1,1,n,1,lst[a[i]],i-lst[a[i]]);
			dp[i][j]=T[j].mn[1];
		}
		lst[a[i]]=i;
	}
	write(dp[n][k]);
}