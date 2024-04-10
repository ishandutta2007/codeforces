#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
template<class T> inline int cmin(T &x,T y){
	return y<x?x=y,1:0;
}
 
const ld pi=acos(-1),inf=1e99;
struct C{
	ld r,i;
	C operator+(const C &o)const{return (C){r+o.r,i+o.i};}
	C operator-(const C &o)const{return (C){r-o.r,i-o.i};}
	C operator/(const ld&o)const{return (C){r/o,i/o};}
	C operator*(const C &o)const{return (C){r*o.r-i*o.i,r*o.i+i*o.r};}
};
typedef vector<ld> po;
 
namespace Poly{
	const int N=(1<<20)+5; int mx;
	void dft(C *a,int n){
		static C W[N<<1],*H[30],*las=W;
		for(;mx<n;mx++){
			H[mx]=las; C w=(C){1,0};
			C wn=(C){cos(pi/(1<<mx)),sin(pi/(1<<mx))};
			REP(i,1<<mx)*las++=w,w=w*wn;
		}
		for(int i=0,j=0;i<(1<<n);i++){
			if(j<i)swap(a[i],a[j]);
			for(int k=1<<(n-1);(j^=k)<k;k>>=1);
		}
		for(int k=0,d=1;k<n;k++,d<<=1)
			for(int i=0;i<(1<<n);i+=d<<1){
				C *l=a+i,*r=a+i+d,*w=H[k];
				for(int j=0;j<d;++j,++l,++r){
					const C t=(*w++)*(*r);
					*r=*l-t,*l=*l+t;
				}
			}
	}
	void idft(C *a,int n){
		reverse(a+1,a+(1<<n));
		dft(a,n); ld pw=1<<n;
		REP(i,1<<n)a[i]=a[i]/pw;
	}
	po mul(po &A,po &B){
		if(min(A.size(),B.size())<=16){
			po res(A.size()+B.size());
			REP(i,A.size())REP(j,B.size())
				res[i+j]+=A[i]*B[j];
			return res;
		}
		static C a[N],b[N];
		int aim=A.size()+B.size()-1,n=1;
		while((1<<n)<=aim)n++;
		REP(i,1<<n)a[i]=b[i]=(C){0,0};
		REP(i,A.size())a[i].r=A[i];
		REP(i,B.size())b[i].r=B[i];
		dft(a,n),dft(b,n);
		REP(i,1<<n)a[i]=a[i]*b[i];
		idft(a,n); po res(aim);
		REP(i,aim)res[i]=a[i].r;
		return res;
	}
}
 
const int N=105,M=20005;
int a[N],b[N],c[N],n,m,T,x;
ld f[N][M],g[N][M],p[N][M],suf[N][M];
 
void solve(int l,int r){
	if(l==r){
		rep(i,1,n-1)f[i][l]=inf;
		rep(i,1,m)cmin(f[a[i]][l],g[i][l]+c[i]
					+suf[i][T+1-l]*f[b[i]][T+1]);
		return;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r);
	po A(r-mid),B(r-l+1),C;
	rep(k,1,m){
		rep(i,mid+1,r)A[r-i]=f[b[k]][i];
		rep(i,1,r-l)B[i]=p[k][i];
		C=Poly::mul(A,B);
		rep(i,l,mid)g[k][i]+=C[r-i];
	}
	solve(l,mid);
}
 
int main(){
	read(n),read(m),read(T),read(x);
	rep(i,1,m){
		read(a[i]),read(b[i]),read(c[i]);
		rep(j,1,T)read(p[i][j]),p[i][j]/=100000;
		per(j,T,1)suf[i][j]=suf[i][j+1]+p[i][j];
	}
	rep(i,1,n)f[i][T+1]=inf; f[n][T+1]=x;
	rep(tmp,1,n)rep(i,1,m)
		cmin(f[a[i]][T+1],f[b[i]][T+1]+c[i]);
	solve(0,T);
	printf("%.8lf\n",(double)f[1][0]);
	return 0;
}