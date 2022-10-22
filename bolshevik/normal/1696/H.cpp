#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int o=610,MOD=1e9+7;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
inline void ad(int&a,int b){a+=b-MOD;a+=(a>>31&MOD);}
int n,m,a[o],pw[o],f[o][o][2],g[o][o][2],s[o][2],h[o],ans,st1[o],tp1,st2[o],tp2;
inline bool cmp(int A,int B){return abs(A)<abs(B);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	a[n+1]=-MOD;a[n+2]=MOD;
	for(int i=1;i<=n;++i) f[i][n+1+(a[i]<0)][a[i]<0]=abs(a[i]);
	for(int i=2;i<=m;++i){
		for(int j=0;j<=n;++j) s[j][0]=s[j][1]=0;
		for(int j=n;j;--j) for(int k=j+1;k<=n+2;++k)
			for(int $=0;$<2;++$) ad(s[j][$],f[j][k][$]),ad(f[j][k][$],f[j+1][k][$]);
		for(int j=n;j;--j) for(int k=j+1;k<=n+2;++k) if(a[j]*1ll*a[k]<0)
			for(int $=0;$<2;++$) g[j][k][$]=(f[j+1][k][$^(a[j]<0)]+s[k][$^(a[j]<0)])*1ll*abs(a[j])%MOD;
		for(int j=n;j;--j) for(int k=j+1;k<=n+2;++k) for(int $=0;$<2;++$) f[j][k][$]=g[j][k][$],g[j][k][$]=0;
	}
	for(int i=1;i<=n+2;++i) if(a[i]>=0) st1[++tp1]=i;else st2[++tp2]=i;
	for(int i=pw[0]=1;i<=n;++i) pw[i]=pw[i-1]*2%MOD;
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n+2;++j) for(int k=0,x,y;k<2;++k) if(f[i][j][k])
		if(!k) ans=(ans+pw[i-1]*1ll*f[i][j][k])%MOD;
		else{
			if(j<n+2) ad(ans,MOD-f[i][j][k]);
			x=a[i];y=a[j];
			if(x<0) swap(x,y);
			y=-y;
			for(int $=1,p1=1,p2=1,invx=qp(x,MOD-2),invy=qp(y,MOD-2);$<i;++$)
				if(st1[p1]<i&&(st2[p2]>=i||(j!=n+2&&a[st1[p1]]*1ll*x<=abs(a[st2[p2]])*1ll*y)))
					ans=(ans+pw[$-1]*1ll*f[i][j][k]%MOD*a[st1[p1++]]%MOD*invy)%MOD;
				else ans=(ans+pw[$-1]*1ll*f[i][j][k]%MOD*abs(a[st2[p2++]])%MOD*invx)%MOD;
		}
	if(m&1){
		for(int i=1;i<tp2;++i) h[i]=abs(a[st2[i]]);
		for(int i=2;i<=m;++i) for(int j=tp2-1;j;h[j]=h[j]*1ll*abs(a[st2[j]])%MOD,--j){
			h[j]=0;
			for(int k=1;k<j;++k) ad(h[j],h[k]);
		}
		for(int i=1;i<tp2;++i) ans=(ans+(MOD-h[i])*1ll*pw[tp2-1-i])%MOD;
	}
	printf("%d",ans);
	return 0;
}