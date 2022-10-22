// Problem: CF817F MEX Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF817F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N=6e5+100;
int n;
int sum[N<<2],len[N<<2],tag[N<<2],r[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void pushr(int x){
	if(tag[x]>=0)tag[x]^=1;
	r[x]^=1;
	sum[x]=len[x]-sum[x];
}
void pusht(int x,int val){
	tag[x]=val;
	sum[x]=val*len[x];
}
void pushdown(int x){
	if(tag[x]!=-1){
		pusht(lc,tag[x]);
		pusht(rc,tag[x]);
	}else if(r[x]){
		pushr(lc);
		pushr(rc);
	}
	tag[x]=-1;
	r[x]=0;
}
void  pushup(int x){
	sum[x]=sum[lc]+sum[rc];
}
void build(int x,int l,int r){
	tag[x]=-1;len[x]=r-l+1;
	if(l==r)return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void rev(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		pushr(x);
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	rev(lc,l,mid,ql,qr);
	rev(rc,mid+1,r,ql,qr);
	pushup(x);
}
void cov(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		pusht(x,val);
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	cov(lc,l,mid,ql,qr,val);
	cov(rc,mid+1,r,ql,qr,val);
	pushup(x);
}
int mex(int x,int l,int r){
	if(l==r)return l;
	pushdown(x);
	if(sum[lc]==len[lc])return mex(rc,mid+1,r);
	return mex(lc,l,mid);
}
vector<int>num;
struct node{
	int op,l,r;
}q[N];
signed main(){
	read(n);num.pb(1);
	auto ins=[&](int x){if(x-1)num.pb(x-1);num.pb(x);num.pb(x+1);};
	for(int i=1;i<=n;i++){
		read(q[i].op,q[i].l,q[i].r);
		ins(q[i].l);ins(q[i].r);
	}
	sort(num.begin(),num.end());
	num.resize(unique(num.begin(),num.end())-num.begin());
	build(1,0,num.size());
	for(int i=1;i<=n;i++){
		int L=q[i].l,R=q[i].r;
		L=lower_bound(num.begin(),num.end(),L)-num.begin();
		R=lower_bound(num.begin(),num.end(),R)-num.begin();
		if(q[i].op==1)
			cov(1,0,num.size(),L,R,1);
		if(q[i].op==2)
			cov(1,0,num.size(),L,R,0);
		if(q[i].op==3)
			rev(1,0,num.size(),L,R);
		write(num[mex(1,0,num.size())]);
		putchar('\n');
	}
}