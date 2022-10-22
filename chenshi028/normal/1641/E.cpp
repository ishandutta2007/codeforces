#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10,MOD=998244353;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}
int n,z[o],m,sp[o],pre[o],suf[o],ans[o],t[o],bt,a[o*3],b[o*3],rev[o*3],yny,whx=1;
inline void ntt(int*a,int n,bool inv){
	for(int i=1;i<n;++i) if((rev[i]=((rev[i>>1]>>1))|((i&1)<<(bt-1)))<i) swap(a[rev[i]],a[i]);
	for(int md=1;md<n;md<<=1){
		int tmp=qp(3,(MOD-1)/(md<<1));
		if(inv) tmp=qp(tmp,MOD-2);
		for(int i=0;i<n;i+=md<<1) for(int j=0,x,y,omega=1;j<md;++j,omega=omega*1ll*tmp%MOD)
			x=a[i+j],y=a[i+j+md]*1ll*omega%MOD,a[i+j]=(x+y)%MOD,a[i+j+md]=(x-y+MOD)%MOD;
	}
}
void slv(int l,int r){
	if(l==r) return;
	int md=l+r>>1;
	slv(l,md);slv(md+1,r);
	for(int i=l;i<=md;++i) a[i-l]=sp[i]*1ll*pre[i-1]%MOD;
	for(int i=r;i>md;--i) b[i-md-1]=suf[i];
	for(bt=0;(1<<bt)<r-l;++bt);
	for(int i=(1<<bt)-1;i>md-l;--i) a[i]=0;
	for(int i=(1<<bt)-1;i>=r-md;--i) b[i]=0;
	ntt(a,1<<bt,0);ntt(b,1<<bt,0);
	for(int i=0;i<(1<<bt);++i) a[i]=a[i]*1ll*b[i]%MOD;
	ntt(a,1<<bt,1);
	for(int i=l+md+1,j=0,v=qp(1<<bt,MOD-2);i<=md+r&&i<=2*n+1;++i) t[i]=(t[i]+a[j++]*1ll*v)%MOD;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=n;i;--i) scanf("%d",&z[i]);
	for(int p;m--;sp[p]=1) scanf("%d",&p),whx=whx*2%MOD;
	for(int i=pre[0]=1;i<=n;++i) pre[i]=pre[i-1]*(sp[i]?2:1)%MOD;
	suf[2*n]=1;
	for(int i=2*n-1;i;--i) suf[i]=suf[i+1]*(sp[i]?2:1)%MOD;
	slv(1,2*n);
	for(int i=1;i<=n;++i) ans[i]=t[i*2]*1ll*i%MOD;
	for(int i=1;i<=2*n;t[i++]=0) sp[i]*=i;
	slv(1,2*n);
	for(int i=1;i<=n;++i) ans[i]=(ans[i]-t[i*2]+MOD)%MOD;
	for(int i=1;i<=2*n+1;++i) t[i]=0;
	for(int i=1,j=n;i<j;swap(ans[i],ans[j]),swap(sp[i++],sp[j--]));
	for(int i=1;i<=n;++i) sp[i]=!!sp[i];
	for(int i=pre[0]=1;i<=n;++i) pre[i]=pre[i-1]*(sp[i]?2:1)%MOD;
	suf[2*n]=1;
	for(int i=2*n-1;i;--i) suf[i]=suf[i+1]*(sp[i]?2:1)%MOD;
	for(int i=1;i<=2*n;++i) suf[i]=suf[i+1];
	slv(1,2*n);
	for(int i=1;i<=n;++i) ans[i]=(ans[i]+t[i*2]*1ll*i)%MOD;
	for(int i=1;i<=2*n;t[i++]=0) sp[i]*=i;
	slv(1,2*n);
	for(int i=1;i<=n;++i) ans[i]=(ans[i]-t[i*2]+MOD)%MOD;
	for(int i=1;i<=n;++i) yny=(yny+ans[i]*1ll*z[i])%MOD;
	printf("%lld",yny*1ll*qp(whx-1,MOD-2)%MOD);
	return 0;
}