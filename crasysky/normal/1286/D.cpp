#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e5+5,P=998244353;
int add(int x,int y){ x+=y; return x>=P?x-P:x; }
int fpw(int x,int y){
	int s=1;
	for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P;
	return s;
}
int inv100=fpw(100,P-2);
struct matrix{
	int a[2][2];
	int* operator [] (int i){ return a[i]; }
};
matrix operator * (matrix A,matrix B){
	matrix C;
	C[0][0]=((ll)A[0][0]*B[0][0]+(ll)A[0][1]*B[1][0])%P;
	C[0][1]=((ll)A[0][0]*B[0][1]+(ll)A[0][1]*B[1][1])%P;
	C[1][0]=((ll)A[1][0]*B[0][0]+(ll)A[1][1]*B[1][0])%P;
	C[1][1]=((ll)A[1][0]*B[0][1]+(ll)A[1][1]*B[1][1])%P;
	return C;
}
struct node{ int l,r; matrix A; }tr[N*4]; matrix M[N];
void up(int u){ tr[u].A=tr[u<<1].A*tr[u<<1|1].A; }
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	if (l==r){ tr[u].A=M[l]; return; }
	int m=l+r>>1; build(u<<1,l,m),build(u<<1|1,m+1,r),up(u);
}
void update(int u,int x){
	if (tr[u].r<x||x<tr[u].l) return;
	if (tr[u].l==tr[u].r){ tr[u].A=M[x]; return; }
	update(u<<1,x),update(u<<1|1,x),up(u);
}
struct data{ int u,v,p,x,y; }a[N*2]; 
bool cmp(data a,data b){ return (ll)a.u*b.v<(ll)b.u*a.v; }
int x[N],v[N],p[N];
int read(){ int x; scanf("%d",&x); return x; }
int main(){
	int n=read(),m=0;
	rep(i,1,n) x[i]=read(),v[i]=read(),p[i]=read();
	rep(i,1,n-1){
		int d=x[i+1]-x[i];
		a[++m]=(data){d,v[i]+v[i+1],i+1,1,0};//right left
		if (v[i]!=v[i+1])//right right || left left
			a[++m]=(data){d,abs(v[i]-v[i+1]),i+1,v[i]>v[i+1],v[i]>v[i+1]};
	}
	sort(a+1,a+1+m,cmp);
	rep(i,1,n){
		int t=(ll)p[i]*inv100%P;
		M[i][0][1]=M[i][1][1]=t,M[i][0][0]=M[i][1][0]=P+1-t;
	}
	build(1,1,n); int ans=0;
	rep(i,1,m){
		int t=a[i].p; matrix tm=M[t];
		M[t][0][0]=M[t][0][1]=M[t][1][0]=M[t][1][1]=0;
		int tmp=(ll)p[t]*inv100%P;
		M[t][a[i].x][a[i].y]=a[i].y==1?tmp:P+1-tmp; update(1,t);
		int p=add(tr[1].A[0][0],tr[1].A[0][1]);
		ans=(ans+(ll)p*a[i].u%P*fpw(a[i].v,P-2))%P;
		M[t]=tm,M[t][a[i].x][a[i].y]=0,update(1,t);
	}
	printf("%d\n",ans);
	return 0;
}