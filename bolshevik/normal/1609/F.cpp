#include<cstdio>
using namespace std;
const int o=1e6+10;const long long inf=1e18+10;
int n,c[o],cnt[o],pmx,pmn;long long a[o],ans,mx,mn,vmx[o],vmn[o],Pmx[o],Pmn[o];
void slv(int l,int r){
	if(l==r){++ans;return;}
	int md=l+r>>1;
	slv(l,md);slv(md+1,r);
	for(int i=0;i<60;++i) cnt[i]=0;
	vmx[md]=mx=-inf;vmn[md]=mn=inf;
	for(int i=md+1;i<=r;++i){
		vmx[i]=vmx[i-1];vmn[i]=vmn[i-1];Pmx[i]=Pmx[i-1];Pmn[i]=Pmn[i-1];
		if(a[i]>vmx[i]) vmx[i]=a[Pmx[i]=i];
		if(a[i]<vmn[i]) vmn[i]=a[Pmn[i]=i];
	}
	for(int L=md,Rmax=md,Rmin=Rmax;L>=l;--L){
		if(a[L]>mx) mx=a[pmx=L];
		if(a[L]<mn) mn=a[pmn=L];
		for(;Rmax<r&&vmx[Rmax+1]<=mx;++cnt[c[Pmn[++Rmax]]]);
		for(;Rmin<Rmax&&vmn[Rmin+1]>mn;--cnt[c[Pmn[++Rmin]]]);
		ans+=(Rmin-md)*(c[pmx]==c[pmn])+cnt[c[pmx]];
	}
	for(int i=0;i<60;++i) cnt[i]=0;
	vmx[md+1]=mx=-inf;vmn[md+1]=mn=inf;
	for(int i=md;i>=l;--i){
		vmx[i]=vmx[i+1];vmn[i]=vmn[i+1];Pmx[i]=Pmx[i+1];Pmn[i]=Pmn[i+1];
		if(a[i]>vmx[i]) vmx[i]=a[Pmx[i]=i];
		if(a[i]<vmn[i]) vmn[i]=a[Pmn[i]=i];
	}
	for(int R=md+1,Lmax=md+1,Lmin=Lmax;R<=r;++R){
		if(a[R]>mx) mx=a[pmx=R];
		if(a[R]<mn) mn=a[pmn=R];
		for(;Lmax>l&&vmx[Lmax-1]<mx;++cnt[c[Pmn[--Lmax]]]);
		for(;Lmin>Lmax&&vmn[Lmin-1]>=mn;--cnt[c[Pmn[--Lmin]]]);
		ans+=(md-Lmin+1)*(c[pmx]==c[pmn])+cnt[c[pmx]];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) for(scanf("%lld",&a[i]),mx=a[i];mx;mx>>=1) c[i]+=(mx&1);
	slv(1,n);
	printf("%lld",ans);
	return 0;
}