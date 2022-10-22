// Problem: CF1320C World of Darkraft: Battle for Azathoth
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1320C
// Memory Limit: 500 MB
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
const int N=1e6+100,MX=1000000+10;
int n,m,k;
int x[N],y[N],z[N];vector<int>id[N];
int m1[N],m2[N];
int mx[N<<2],tag[N<<2];
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
void build(int x,int l,int r){
	if(l==r){
		mx[x]=m2[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void upd(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		mx[x]+=val;
		tag[x]+=val;
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	upd(lc,l,mid,ql,qr,val);
	upd(rc,mid+1,r,ql,qr,val);
	pushup(x);
}
signed main(){
	read(n,m,k);
	for(int i=1;i<=MX;i++)m1[i]=m2[i]=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		int a,c;read(a,c);
		chkmx(m1[a],-c);
	}
	for(int i=1;i<=m;i++){
		int a,c;read(a,c);
		chkmx(m2[a],-c);
	}
	for(int i=1;i<=k;i++){
		read(x[i],y[i],z[i]);x[i]++,y[i]++;
		id[x[i]].push_back(i);
	}
	build(1,1,MX);
	int ans=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=MX;i++){
		for(auto j:id[i])
			upd(1,1,MX,y[j],MX,z[j]);
		chkmx(ans,mx[1]+m1[i]);
	}
	write(ans);
}