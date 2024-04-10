#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100000
#define mod 1000000007
int n,a[N+1];
struct matrix{
	int a[2][2];
	matrix(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	matrix(bool x){a[0][0]=a[1][1]=1;a[0][1]=a[1][0]=0;}
	matrix(bool x,bool y){a[0][0]=a[0][1]=a[1][0]=1;a[1][1]=0;}
	int *operator[](int x){return a[x];}
}unit(0);
matrix operator+(matrix a,matrix b){
	a[0][0]=(a[0][0]+b[0][0])%mod;
	a[0][1]=(a[0][1]+b[0][1])%mod;
	a[1][0]=(a[1][0]+b[1][0])%mod;
	a[1][1]=(a[1][1]+b[1][1])%mod;
	return a;
}
matrix operator*(matrix &a,matrix b){
	matrix c;
	c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%mod;
	c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%mod;
	c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%mod;
	c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%mod;
	return c;
}
bool operator!=(matrix a,matrix b){
	return a[0][0]!=b[0][0]||a[0][1]!=b[0][1]||a[1][0]!=b[1][0]||a[1][1]!=b[1][1];
}
matrix power(int x){
	matrix res(0),base(0,0);
	while(x){
		if(x&1)res=res*base;
		base=base*base;
		x>>=1;
	}
	return res;
}
struct node{int l,r;matrix sum,lz;}nd[N<<2];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define lz(x) nd[x].lz
#define sum(x) nd[x].sum
void bld(int l=1,int r=n,int p=1){
	l(p)=l;r(p)=r;lz(p)=unit;
	if(l==r){sum(p)=power(a[l]-1);return;}
	int mid=l+r>>1;
	bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
void spr(int p){
	if(lz(p)!=unit){
		matrix x=lz(p);lz(p)=unit;
		lz(p<<1)=lz(p<<1)*x;lz(p<<1|1)=lz(p<<1|1)*x;
		sum(p<<1)=sum(p<<1)*x;sum(p<<1|1)=sum(p<<1|1)*x;
	}
}
void chg(int l,int r,matrix v,int p=1){
	if(l<=l(p)&&r>=r(p)){sum(p)=sum(p)*v;lz(p)=lz(p)*v;return;}
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)chg(l,r,v,p<<1);
	if(r>mid)chg(l,r,v,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
matrix ask(int l,int r,int p=1){
	if(l<=l(p)&&r>=r(p))return sum(p);
	spr(p);
	int mid=l(p)+r(p)>>1;
	matrix res;
	if(l<=mid)res=res+ask(l,r,p<<1);
	if(r>mid)res=res+ask(l,r,p<<1|1);
	return res;
}
signed main(){
	int qu;scanf("%lld%lld",&n,&qu);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	bld();
	while(qu--){
		int tp,x,y,z;scanf("%lld%lld%lld",&tp,&x,&y);
		if(tp==1)scanf("%lld",&z),chg(x,y,power(z));
		else printf("%lld\n",ask(x,y)[0][0]);
	}
	return 0;
}
/*1
5 4
1 1 2 1 1
2 1 5
1 2 4 2
2 2 4
2 1 5
*/