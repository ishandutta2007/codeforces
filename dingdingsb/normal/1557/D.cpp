// Problem: D. Ezzat and Grid
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
//#define int long long
typedef long long ll;
const int N=6e5+100;
int n,m;
vector<pair<int,int>>e[N];
vector<int>num;
struct SGT{
	pair<int,int>mx[N<<2],tag[N<<2];
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void pushup(int x){
		mx[x]=max(mx[lc],mx[rc]);
	}
	void pushdown(int x){
		if(tag[x].second){
			chkmx(mx[lc],tag[x]);
			chkmx(tag[lc],tag[x]);
			chkmx(mx[rc],tag[x]);
			chkmx(tag[rc],tag[x]);
			tag[x]={0,0};
		}
	}
	void upd(int x,int l,int r,int ql,int qr,pair<int,int>val){
		if(ql<=l&&r<=qr){
			chkmx(mx[x],val);
			chkmx(tag[x],val);
			return;
		}
		if(r<ql||qr<l)return;
		pushdown(x);
		upd(lc,l,mid,ql,qr,val);
		upd(rc,mid+1,r,ql,qr,val);
		pushup(x);
	}
	pair<int,int>qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mx[x];
		if(r<ql||qr<l)return {0,0};
		pushdown(x);
		return max(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T;
pair<int,int>dp[N];bool flag[N];
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		int id,l,r;read(id,l,r);
		e[id].pb(mp(l,r));
		num.pb(l);num.pb(r);
	}
	sort(num.begin(),num.end());
	num.resize(unique(num.begin(),num.end())-num.begin());
	auto get=[&](int x){
		return lower_bound(num.begin(),num.end(),x)-num.begin()+1;
	};
	int tot=num.size();
	for(int i=1;i<=n;i++)
		for(auto&[l,r]:e[i])
			l=get(l),r=get(r);
	for(int i=1;i<=n;i++){
		dp[i]={0,0};
		for(auto[l,r]:e[i])
			chkmx(dp[i],T.qry(1,1,tot,l,r));
		dp[i].first++;
		for(auto[l,r]:e[i])
			T.upd(1,1,tot,l,r,mp(dp[i].first,i));
	}
	pair<int,int>ans={0,0};
	for(int i=1;i<=n;i++)chkmx(ans,mp(dp[i].first,i));
	write(n-ans.first);putchar('\n');
	int x=ans.second;
	while(x)flag[x]=1,x=dp[x].second;
	for(int i=1;i<=n;i++)
		if(!flag[i])write(i),putchar(' ');
}