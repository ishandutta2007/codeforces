// : caigou
// : 2021-12-04 07:47

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
using namespace __gnu_pbds;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
//SAMDAG
// +/-1
// 0 
const int N=2e6+100;
int n,a[N];char s[N];
struct SAM{
	int ch[N][2],fa[N],l[N],lst,sz;
	SAM(){lst=sz=1;}
	void add(int c){
		int cur=++sz,p=lst;
		l[cur]=l[p]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=cur;
		if(!p)fa[cur]=1;
		else{
			int q=ch[p][c];
			if(l[q]==l[p]+1)fa[cur]=q;
			else{
				int nw=++sz;
				l[nw]=l[p]+1;
				fa[nw]=fa[q];
				memcpy(ch[nw],ch[q],sizeof ch[q]);
				for(;ch[p][c]==q;p=fa[p])
					ch[p][c]=nw;
				fa[q]=fa[cur]=nw;
			}
		}
		lst=cur;
	}
}S;
int endpos[N];
vector<int>e[N];
vector<pair<int,int>>qry[500010];// i  [fi,se]
void dfs(int u){
	for(auto v:e[u]){
		dfs(v);
		if(!endpos[u])endpos[u]=endpos[v];
	}
	qry[endpos[u]].pb(mp(S.l[S.fa[u]]+1,S.l[u]));
}
ll ans;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rbt;
rbt pos[1000010];
int rk(int x,rbt&T){
	//<xT
	auto it=T.lower_bound(x);
	if(it==T.end())return T.size();
	return T.order_of_key(*it);
}
int cnt(int l,int r,rbt&T){
	return rk(r+1,T)-rk(l,T);
}
int sum[N];
struct SGT{
	int mn[N];
	void build(int x,int l,int r){
		if(l==r)return mn[x]=sum[l],void();
		build(lc,l,mid);build(rc,mid+1,r);
		mn[x]=min(mn[lc],mn[rc]);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(r<ql||qr<l)return 0x3f3f3f3f;
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T;
signed main(){
	read(n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='(')S.add(1),a[i]=-1;
		else S.add(0),a[i]=1;
		endpos[S.lst]=i;
	}
	for(int i=n;i;i--)sum[i]=sum[i+1]+a[i];
	for(int i=2;i<=S.sz;i++)e[S.fa[i]].pb(i);
	dfs(1);
	T.build(1,1,n);
	for(int i=1;i<=n;i++){
		//i
		pos[sum[i]+n].insert(i);
		while(pos[sum[i+1]+n].size()){
			int kk=*pos[sum[i+1]+n].begin();
			if(T.qry(1,1,n,kk,i)<sum[i+1])pos[sum[i+1]+n].erase(pos[sum[i+1]+n].begin());
			else break;
		}
		for(auto X:qry[i])
			ans+=cnt(i-X.se+1,i-X.fi+1,pos[sum[i+1]+n]);
	}
	write(ans);
}