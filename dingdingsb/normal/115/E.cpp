// Problem: CF115E Linear Kingdom Races
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF115E
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define int long long
typedef long long ll;
const int N=2e5+100;
int n,m,l[N],r[N],p[N],s[N];vector<int>id[N];
int dp[N],mx[N<<2],tag[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void pushdown(int x){
	mx[lc]+=tag[x];
	tag[lc]+=tag[x];
	mx[rc]+=tag[x];
	tag[rc]+=tag[x];
	tag[x]=0;
}
void pushup(int x){
	mx[x]=max(mx[lc],mx[rc]);
}
void upd(int x,int l,int r,int pos,int val){
	if(l==r){
		mx[x]=val;
		return;
	}
	pushdown(x);
	if(pos<=mid)upd(lc,l,mid,pos,val);
	else upd(rc,mid+1,r,pos,val);
	pushup(x);
}
void add(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		mx[x]+=val;
		tag[x]+=val;
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	add(lc,l,mid,ql,qr,val);
	add(rc,mid+1,r,ql,qr,val);
	pushup(x);
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)
		read(s[i]),s[i]+=s[i-1];
	for(int i=1;i<=m;i++)
		read(l[i],r[i],p[i]),id[r[i]].pb(i);
	for(int i=1;i<=n;i++){
		for(auto j:id[i])
			add(1,0,n,0,l[j]-1,p[j]);
		dp[i]=max(dp[i-1],mx[1]-s[i]);
		upd(1,0,n,i,dp[i]+s[i]);
	}
	int res=0;for(int i=1;i<=n;i++)chkmx(res,dp[i]);
	write(res);
}