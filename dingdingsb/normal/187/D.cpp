// Problem: C. ?1 ZR day10?
// Contest: UOJ - 21noip20?day10
// URL: http://zhengruioi.com/contest/1025/problem/2102
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
const int N=4e5+100;
int n,g,r;
int l[N];
int q,lst;
int sum[N];//+r
int dp[N];
struct SGT{
	vector<int>nums;
	int mn[N<<2];
	void pushup(int x){
		mn[x]=min(mn[lc],mn[rc]);
	}
	void build(int x,int l,int r){
		mn[x]=n+1;
		if(l==r)return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void build(){
		sort(nums.begin(),nums.end());
		nums.resize(unique(nums.begin(),nums.end())-nums.begin());
		build(1,0,nums.size()-1);
	}
	void upd(int x,int l,int r,int pos,int val){
		if(l==r){
			mn[x]=val;
			return;
		}
		if(pos<=mid)upd(lc,l,mid,pos,val);
		else upd(rc,mid+1,r,pos,val);
		pushup(x);
	}
	void upd(int pos,int val){
		pos=lower_bound(nums.begin(),nums.end(),pos)-nums.begin();
		upd(1,0,nums.size()-1,pos,val);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(r<ql||qr<l)return n+1;
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
	int qry(int ql,int qr){
		ql=lower_bound(nums.begin(),nums.end(),ql)-nums.begin();
		qr=upper_bound(nums.begin(),nums.end(),qr)-nums.begin()-1;
		return qry(1,0,nums.size()-1,ql,qr);
	}
}T;
int fi(int kk){
	kk%=(g+r);
	if(kk+g>=g+r){
		int l=(kk+g)%(g+r);
		int r=(kk+g+::r-1)%(g+::r);
		return T.qry(l,r);
	}
	if(kk+g+r-1<(g+r))
		return T.qry(kk+g,kk+g+r-1);
	else
		return min(T.qry(kk+g,g+r-1),T.qry(0,(kk+g+r-1)%(g+r)));
}
signed main(){
	//freopen("C.in","r",stdin);
	read(n,g,r);int s=0;
	for(int i=1;i<=n+1;i++)read(l[i]),s+=l[i],sum[i]=(sum[i-1]+l[i])%(g+r);
	for(int i=1;i<=n;i++)T.nums.pb(sum[i]);
	T.build();
	T.upd(sum[n],n);
	for(int i=n-1;i>=1;i--){
		//
		int id=fi(sum[i]);
		if(id==n+1)dp[i]=0;
		else dp[i]=dp[id]+(2*(g+r)-(sum[id]-sum[i]))%(g+r);
		T.upd(sum[i],i);
	}
	read(q);while(q--){
		int t;read(t);
		//t^=(lst%2147483647);
		int id=fi(g+r-t%(g+r));
		int more=dp[id]+(2*(g+r)-(sum[id]+t)%(g+r))%(g+r);
		if(id==n+1)more=0;
		write(lst=t+more+s);pc('\n');
	}
}