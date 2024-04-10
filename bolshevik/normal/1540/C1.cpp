#include<cstdio>
#include<iostream>
using namespace std;
const int o=110,MOD=1e9+7;
inline void ad(int&a,const int&b){a+=b-MOD;a+=(a>>31&MOD);}
int n,q,c[o],b[o],ans[o*2],f[o][o*o],lim,Ans=1,x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]),Ans=Ans*(c[i]+1ll)%MOD;
	for(int i=2;i<=n;++i) scanf("%d",&b[i]),b[i]+=b[i-1];
	for(int i=2;i<=n;++i) b[i]+=b[i-1];
	f[0][0]=1;
	for(int i=1;i<=n;++i) lim=min(lim,-((b[i]+i-1)/i));
	for(int i=lim;i<=lim+200;++i){
		for(int j=1;j<=n;++j) for(int k=0;k<=10000;++k) f[j][k]=0;
		for(int j=1;j<=n;++j){
			for(int k=max(0,j*i+b[j]-c[j]);k<=10000;++k)
				if(f[j-1][k]) ad(f[j][max(k,j*i+b[j])],f[j-1][k]),ad(f[j][k+c[j]+1],MOD-f[j-1][k]);
			for(int k=1;k<=10000;++k) ad(f[j][k],f[j][k-1]);
		}
		for(int j=0;j<=10000;++j) ad(ans[i-lim],f[n][j]);
	}
	for(scanf("%d",&q);q--;printf("%d\n",x>lim+200?0:x<lim?Ans:ans[x-lim])) scanf("%d",&x);
	return 0;
}