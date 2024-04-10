// Problem: E. Divan and a Cottage
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
#define mid ((l+r)>>1)
typedef long long ll;
const int N=2e5+100;
int n;int lst;
struct SGT{
	int lc[N<<5],rc[N<<5],sum[N<<5],tot;
	void pushup(int x){sum[x]=sum[lc[x]]+sum[rc[x]];}
	int qry(int x,int l,int r,int ql,int qr){
		if(!x)return 0;
		if(ql<=l&&r<=qr)return sum[x];
		if(r<ql||qr<l)return 0;
		return qry(lc[x],l,mid,ql,qr)+qry(rc[x],mid+1,r,ql,qr);
	}
	void upd(int&x,int l,int r,int pos,int val){
		if(!x)x=++tot;
		if(l==r){
			sum[x]+=val;
			return;
		}
		if(pos<=mid)upd(lc[x],l,mid,pos,val);
		else upd(rc[x],mid+1,r,pos,val);
		pushup(x);
	}
}T;
#define RANGE 0,1e9
int root;
int get(int val){
	return T.qry(root,RANGE,0,val)+val;
}
int lowerbound(int x){
	int l=0,r=1e9,ans=0;
	while(l<=r){
		if(get(mid)>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int upperbound(int x){
	int l=0,r=1e9,ans=1e9+1;
	while(l<=r){
		if(get(mid)>x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++){
		int Ti;read(Ti);
		//[0,k-1] {k} [k+1,1e9]
		if(Ti<get(0))
			T.upd(root,RANGE,0,-1);
		else if(Ti==get(0)){
			int kk=upperbound(Ti);
			if(kk<=1e9)
			T.upd(root,RANGE,kk,-1);
		}else if(get(1e9)<Ti)
			T.upd(root,RANGE,0,+1);
		else if(get(1e9)==Ti){
			int kk=lowerbound(Ti);
			if(kk>0)
			T.upd(root,RANGE,0,1),
			T.upd(root,RANGE,kk,-1);
		}else{
			int l=lowerbound(Ti),r=upperbound(Ti);
			T.upd(root,RANGE,0,+1),
			T.upd(root,RANGE,l,-1);
			if(r<=1e9)
			T.upd(root,RANGE,r,-1);
		}
		int k;read(k);while(k--){
			int x;read(x);x=(lst+x)%(1000000001);
			write(lst=get(x));pc('\n');
		}
	}
	return 0;
	cout<<"c*fnmsl";
}