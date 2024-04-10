// Problem: CF1422F Boring Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1422F
// Memory Limit: 500 MB
// Time Limit: 3000 ms
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
//#define int long long
#define mid ((l+r)>>1)
typedef long long ll;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    modint<mod> operator - () {return x?mod-x:0;}
};
enum{mod=1000000000+7};
using mint=modint<mod>;
const int N=2e5+100;
int n,m,a[N],rt[N];
struct node{
	mint prod;
	int lc,rc;
}t[N*150];
int tot;
int build(int l,int r){
	int x=++tot;
	t[x].prod=1;
	if(l==r)return x;
	t[x].lc=build(l,mid);
	t[x].rc=build(mid+1,r);
	return x;
}
int mdf(int y,int l,int r,int pos,mint val){
	int x=++tot;t[x]=t[y];t[x].prod*=val;
	if(l==r)return x;
	if(pos<=mid)t[x].lc=mdf(t[y].lc,l,mid,pos,val);
	else t[x].rc=mdf(t[y].rc,mid+1,r,pos,val);
	return x;
}
mint qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return t[x].prod;
	if(r<ql||qr<l)return 1;
	return qry(t[x].lc,l,mid,ql,qr)*qry(t[x].rc,mid+1,r,ql,qr);
}
int f[N];
stack<pair<int,int>>s[N];
mint inv[N];
signed main(){
	inv[1]=1;for(int i=2;i<N;i++)inv[i]=-inv[mod%i]*(mod/i);
	for(int i=2;i<N;i++)if(!f[i])
		for(int j=i;j<N;j+=i)f[j]=i;
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	rt[0]=build(1,n);
	for(int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		while(a[i]>1){
			int p=f[a[i]],kk=1;
			while(a[i]%p==0)a[i]/=p,kk*=p;mint lst=1;
			while(s[p].size()&&s[p].top().se<=kk){
				int pos=s[p].top().fi;
				int val=s[p].top().se;s[p].pop();
				rt[i]=mdf(rt[i],1,n,pos,inv[val]*lst);
				lst=val;
			}
			if(s[p].size())
				rt[i]=mdf(rt[i],1,n,s[p].top().fi,inv[kk]*lst);
			rt[i]=mdf(rt[i],1,n,i,kk);
			s[p].push(mp(i,kk));
		}
	}
	read(m);mint lst=0;
	while(m--){
		int l,r;read(l,r);
		l=(l+lst.x)%n+1,r=(r+lst.x)%n+1;
		if(l>r)swap(l,r);
		//printf("%d %d\n",l,r);
		write((lst=qry(rt[r],1,n,l,r)).x);pc('\n');
	}
}