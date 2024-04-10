// Problem: CF718C Sasha and Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF718C
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
//#define int long long
typedef long long ll;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator ^=(int b){
        modint<mod> a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint<mod> &operator /=(modint<mod> o){return *this *=o^=mod-2;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint<mod> &operator /=(int o){return *this *= ((modint<mod>(o))^=mod-2);}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    template<class I>friend modint<mod> operator /(modint<mod> a,I b){return a/=b;}
    friend modint<mod> operator ^(modint<mod> a,int b){return a^=b;}
    friend bool operator ==(modint<mod> a,int b){return a.x==b;}
    friend bool operator !=(modint<mod> a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint<mod> operator - () {return x?mod-x:0;}
    modint<mod> &operator++(int){return *this+=1;}
};
typedef modint<1000000007>mint;
struct matrix{
	mint a[2][2];
	matrix(){memset(a,0,sizeof a);}
	matrix(mint A,mint B,mint C,mint D){a[0][0]=A,a[0][1]=B,a[1][0]=C,a[1][1]=D;}
	mint*operator[](int x){return a[x];}
	matrix operator*(matrix b)const{
		matrix c=matrix(0,0,0,0);
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					c[i][k]+=a[i][j]*b[j][k];
		return c;
	}
	matrix operator+(matrix b)const{
		return matrix(a[0][0]+b[0][0],a[0][1]+b[0][1],
					  a[1][0]+b[1][0],a[1][1]+b[1][1]);
	}
};
matrix I=matrix(1,0,0,1);
matrix ksm(int b){
	matrix res=I,a=matrix(1,1,1,0);
	while(b){
		if(b&1)res=res*a;
		a=a*a;b>>=1;
	}return res;
}
const int N=1e5+100;
int n,m;int a[N];
matrix s[N<<2],tag[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void pushdown(int x){
	s[lc]=s[lc]*tag[x];
	s[rc]=s[rc]*tag[x];
	tag[lc]=tag[lc]*tag[x];
	tag[rc]=tag[rc]*tag[x];
	tag[x]=I;
}
void pushup(int x){
	s[x]=s[lc]+s[rc];
}
void build(int x,int l,int r){
	tag[x]=I;
	if(l==r){
		s[x]=ksm(a[l]);
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void upd(int x,int l,int r,int ql,int qr,matrix val){
	if(ql<=l&&r<=qr){
		s[x]=s[x]*val;
		tag[x]=tag[x]*val;
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	upd(lc,l,mid,ql,qr,val);
	upd(rc,mid+1,r,ql,qr,val);
	pushup(x);
}
mint get(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return s[x][1][0];
	if(r<ql||qr<l)return 0;
	pushdown(x);
	return get(lc,l,mid,ql,qr)+get(rc,mid+1,r,ql,qr);
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	while(m--){
		int op,l,r,val;read(op,l,r);
		if(op==1){
			read(val);
			upd(1,1,n,l,r,ksm(val));
		}else{
			write(get(1,1,n,l,r).x);
			putchar('\n');
		}
	}
}