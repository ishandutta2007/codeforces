// Problem: C. Optimal Insertion
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
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
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=2e6+100;
int t,n,m;
int cntz[N<<1],cntf[N<<1];
int ans[N<<1];
void build(int x,int l,int r){
	cntz[x]=cntf[x]=ans[x]=0;
	if(l==r)return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void pushup(int x){
	cntz[x]=cntz[lc]+cntz[rc];
	cntf[x]=cntf[lc]+cntf[rc];
	ans[x]=min(cntz[lc]+cntf[rc],min(ans[lc]+cntf[rc],cntz[lc]+ans[rc]));
}
int a[N],b[N];
void upd(int x,int l,int r,int pos,int val){
	if(l==r){
		cntz[x]=cntf[x]=ans[x]=0;
		if(val==1)cntz[x]=1;
		if(val==-1)cntf[x]=1;
		return;
	}
	if(pos<=mid)upd(lc,l,mid,pos,val);
	else upd(rc,mid+1,r,pos,val);
	pushup(x);
}
vector<int>id[N];
int cntb[N];
vector<int>num;
struct BIT{
	int tree[N];
	void clear(){
		for(int i=0;i<=num.size()+1;i++)
			tree[i]=0;
	}
	#define lowbit(x) (x&-x)
	void upd(int x){
		for(;x<=num.size();x+=lowbit(x))
			tree[x]++;
	}
	int qry(int x){
		int res=0;
		for(;x;x-=lowbit(x))
			res+=tree[x];
		return res;
	}
	int qry(int l,int r){
		return qry(r)-qry(l-1);
	}
}TTT;
signed main(){
	read(t);
	while(t--){
		read(n,m);
		for(int i=1;i<=n+m;i++)id[i].clear(),cntb[i]=0;
		num.clear();
		for(int i=1;i<=n;i++)read(a[i]),num.pb(a[i]);
		for(int i=1;i<=m;i++)read(b[i]),num.pb(b[i]);
		sort(num.begin(),num.end());
		num.resize(unique(num.begin(),num.end())-num.begin());
		for(int i=1;i<=n;i++)a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
		for(int i=1;i<=m;i++)b[i]=lower_bound(num.begin(),num.end(),b[i])-num.begin()+1;
		for(int i=1;i<=n;i++)id[a[i]].pb(i);
		for(int i=1;i<=m;i++)cntb[b[i]]++;
		build(1,1,n);
		for(int i=1;i<=n;i++)upd(1,1,n,i,1);
		ll A=0;
		for(int i=1;i<=num.size();i++){
			for(auto x:id[i])upd(1,1,n,x,0);
			A+=1ll*cntb[i]*min(min(cntz[1],cntf[1]),ans[1]);
			for(auto x:id[i])upd(1,1,n,x,-1);
		}
		TTT.clear();
		for(int i=1;i<=n;i++){
			A+=TTT.qry(a[i]+1,num.size());
			TTT.upd(a[i]);
		}
		write(A);pc('\n');
	}
}