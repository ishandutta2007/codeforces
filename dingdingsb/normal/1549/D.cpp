// Problem: D. Integers Have Friends
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/D
// Memory Limit: 256 MB
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
const int N=2e5+100;
int t,n,a[N],b[N];
struct SGT{
	int val[N<<2];
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void pushup(int x){
		val[x]=__gcd(val[lc],val[rc]);
	}
	void build(int x,int l,int r){
		if(l==r){
			val[x]=b[l];
			return;;
		}
		
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return val[x];
		if(qr<l||r<ql)return 0;
		return __gcd(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T;
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<n;i++)b[i]=abs(a[i]-a[i+1]);
		if(n==1){write(1);putchar('\n');continue;;}
		T.build(1,1,n-1);
		int l=1,r=0,ans=1;int now=0;
		for(;l<n;){
			while(r+1<n&&__gcd(now,b[r+1])>1)
				r++,now=__gcd(now,b[r]);
			if(now>1)ans=max(ans,r-l+2);
			l++;chkmx(r,l-1);
			if(l<=r)now=T.qry(1,1,n-1,l,r);
			else now=0;
		}
		write(ans);putchar('\n');
	}
}