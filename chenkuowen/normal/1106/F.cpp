#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
struct Matrix{
	int a[105][105];
	int* operator[](int x){ return a[x]; }
	Matrix(){memset(a,0,sizeof(a)); }
	Matrix operator*(Matrix b){
		Matrix c;
		for(int i=0;i<100;++i)
			for(int j=0;j<100;++j)
				for(int k=0;k<100;++k)
					c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%(MOD-1);
		return c;
	}
};
int solve1(int b[],int k,int n,int m){
	Matrix base,ans;
	for(int i=1;i<k;++i) base[i][i-1]=1;
	for(int i=1;i<=k;++i) base[k-i][k-1]=b[i];
	n-=k;
	ans[0][k-1]=1;
	for(;n;n>>=1,base=base*base)
		if(n&1) ans=ans*base;
	return ans[0][k-1];
}
int bsgs(int a,int b,int c,int m){
	unordered_map<int,int> h;
	if(a==c) return 0;
	int q=1<<15,b2=1;
	for(int i=1;i<=q;++i){
		c=1ll*c*b%MOD;
		b2=1ll*b2*b%MOD;
		h[c]=i;
	}
	for(int i=1;i<=m/q+1;++i){
		a=1ll*a*b2%MOD;
		int k=h[a];
		if(k!=0) return i*q-k;
	}
	return -1;
}
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
int b[(int)1e5+5];
int main(){
	int n,m,k;
	scanf("%d",&k);
	for(int i=1;i<=k;++i) scanf("%d",&b[i]);
	scanf("%d%d",&n,&m);
	int c=solve1(b,k,n,m);
	c=fpow(3,c);
	int d=bsgs(1,c,m,MOD);
	if(d==-1) puts("-1");
	else printf("%d\n",fpow(3,d));
	return 0;
}