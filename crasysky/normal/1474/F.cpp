#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<double,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=102,P=998244353;
struct matrix{ int a[N][N]; }M[N],T[N];
matrix mul(matrix A,matrix B,int n){
	static ll ans[N][N];
	rep(i,0,n) rep(j,0,n) ans[i][j]=0;
	rep(i,0,n)
		rep(k,0,n)
			rep(j,0,n) ans[i][j]+=(ll)A.a[i][k]*B.a[k][j];
	matrix C; rep(i,0,n) rep(j,0,n) C.a[i][j]=ans[i][j]%P;
	return C;
}
matrix fpw(matrix A,int y,int n){
	matrix C; rep(i,0,n) rep(j,0,n) C.a[i][j]=i==j;
	for (;y;y>>=1,A=mul(A,A,n)) if (y&1) C=mul(C,A,n);
	return C;
}
int add(int x,int y){ x+=y; return x>=P?x-P:x; }
ll l[N],r[N],b[N]; int p[N],pos[N];
int main(){
	int n; ll x; scanf("%d%lld",&n,&x); r[0]=x;
	ll mn=x,ans=1,s=1;
	rep(i,1,n){
		int d; scanf("%d",&d); 
		if (d==0) --i,--n;
		x+=d,r[i]=x;
		s+=d>0?d:-d,ans=max(ans,x-mn+1),mn=min(mn,x);
	}
	if (ans==1){ cout<<ans<<" "<<s%P<<endl; return 0; }
	int m=0; rep(i,0,n) b[++m]=r[i];
	sort(b+1,b+1+m),m=unique(b+1,b+1+m)-b-1;
	rep(i,0,n) p[i]=lower_bound(b+1,b+1+m,r[i])-b;
	rep(i,0,n) pos[p[i]]=i;
	rep(i,1,m-1) M[i].a[0][0]=1;
	rep(i,1,m) T[i].a[0][0]=1; T[p[0]].a[1][0]=1;
	mn=r[0]; int sum=0;
	rep(k,1,n){
		rep(i,1,m-1) rep(j,0,n+1) M[i].a[k+1][j]=M[i].a[k][j];
		rep(i,1,m) rep(j,0,n+1) T[i].a[k+1][j]=T[i].a[k][j];
		if (r[k-1]<r[k]){//( p[k-1], p[k] ]
			rep(i,p[k-1],p[k]-1) ++M[i].a[k+1][k+1],++T[i+1].a[k+1][k+1];
			if (pos[p[k]]==k&&r[k]-mn+1==ans){
				matrix V=T[1];
				rep(i,2,p[k]){
					V=mul(T[i],mul(fpw(M[i-1],b[i]-b[i-1]-1,k+1),V,k+1),k+1);
				}
				sum=add(sum,V.a[k+1][0]);
			}
		}
		else{//[ p[k], p[k-1] )
			rep(i,p[k],p[k-1]-1) ++M[i].a[k+1][k],++T[i].a[k+1][k];
			if (mn>r[k]){
				rep(i,1,m) rep(j,0,n+1) M[i].a[k+1][j]=T[i].a[k+1][j]=0;
				mn=r[k];
			}
			if (mn==r[k]) ++T[p[k]].a[k+1][0];
		}
	}
	cout<<ans<<" "<<sum<<endl;
	return 0;
}