#include<cstdio>
#include<iostream>
using namespace std;
const int o=310,O=1010,MOD=1e9+7;
inline void ad(int&a,int b){a+=b-MOD;a+=(a>>31&MOD);}
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,a[o],d[o],A[o][o],q,lamd[o],f[o][o],w[o][o],pw[o][O],ipw[o][O],s[o],ans;
inline int lowbit(int x){return x&-x;}
struct FenwickTree{
	int b[o];
	inline void clear(){for(int i=0;i<=n;++i) b[i]=0;}
	inline void build(){
		for(int i=1;i<=n;++i) s[i]=s[i-1],ad(s[i],b[i-1]);
		for(int i=1;i<=n;++i) b[i]=s[i],ad(b[i],MOD-s[i^lowbit(i)]);
	}
	inline void modify(int pos,int val){for(++pos;pos<=n;pos+=lowbit(pos)) ad(b[pos],val);}
	inline int query(int pos){int res=0;for(++pos;pos;pos-=lowbit(pos)) ad(res,b[pos]);return res;}
}z[o];
inline void Inv(){
	for(int i=1;i<=n;++i) for(int j=1;j<i;++j)
		for(int k=1;k<=j;++k) w[i][k]=(w[i][k]+(MOD-f[i][j])*1ll*w[j][k])%MOD;
}
inline void build(){
	for(int i=n,j;i;--i) for(d[i]=(a[i]>0?0:O),j=i+1;j<=n;++j) if(A[i][j]) d[i]=min(d[i],d[j]+1);
	for(int i=1,j;i<=n;z[i++].build()) for(z[i].clear(),j=i;j<=n;++j)
		if(d[j]<O) z[i].b[d[j]]=(z[i].b[d[j]]+w[j][i]*1ll*(a[j]+MOD)%MOD*ipw[lamd[i]][d[j]])%MOD;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),f[i][i]=w[i][i]=1;
	for(int i=1,c,d;i<=n;++i) for(scanf("%d",&c),lamd[i]=A[i][i]=i;c--;A[i][d]=d) scanf("%d",&d);
	for(int i=1;i<=n;++i) for(int j=pw[i][0]=ipw[i][0]=1,t=qp(i,MOD-2);j<O;++j)
		pw[i][j]=pw[i][j-1]*1ll*i%MOD,ipw[i][j]=ipw[i][j-1]*1ll*t%MOD;
	for(int i=1;i<=n;++i) for(int j=i;--j;f[i][j]=f[i][j]*1ll*ipw[lamd[i]-A[j][j]][1]%MOD)
		for(int k=j+1;k<=i;++k) f[i][j]=(f[i][j]+A[j][k]*1ll*f[i][k])%MOD;
	Inv();build();
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) ad(f[i][j],f[i][j-1]);
	scanf("%d",&q);
	for(int opt,k,l,r;q--;){
		scanf("%d%d%d",&opt,&k,&l);
		if(opt==1){
			scanf("%d",&r);ans=0;
			for(int i=l;i<=r;++i) if(d[i]>k) ad(ans,a[i]+MOD);
			for(int i=1;i<=n;++i)
				ans=(ans+z[i].query(min(k,n-1))*1ll*pw[lamd[i]][k]%MOD*(f[i][r]+MOD-f[i][l-1]))%MOD;
			printf("%d\n",ans);
		}
		else if(a[k]<=0&&a[k]+l>0) a[k]+=l,build();
		else{
			if(d[k]<O) for(int i=1;i<=n;++i) z[i].modify(d[k],w[k][i]*1ll*l%MOD*ipw[lamd[i]][d[k]]%MOD);
			a[k]+=l;
		}
	}
	return 0;
}