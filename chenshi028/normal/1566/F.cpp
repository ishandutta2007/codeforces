#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=2e5+10,inf=2e9+10;
#define int long long
inline int Min(int a,int b){return a<b?a:b;} 
int T,n,a[o],m,cnt,g[o];bool vis[o];
struct segment{int l,r;}se[o];vector<int> f[o];
inline bool cmp(segment A,segment B){if(A.l^B.l) return A.l>B.l;return A.r<B.r;}
inline void slv(){
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=m;++i) read(se[i].l),read(se[i].r);
	sort(se+1,se+1+m,cmp);
	for(int i=1,mnr=inf;i<=m;++i) vis[i]=(se[i].r>=mnr),mnr=Min(mnr,se[i].r);
	for(int i=1,l,r,md;i<=m;vis[i]|=(l<=n&&a[l]<=se[i].r),++i)
		for(l=1,r=n+1;l<r;) if(a[md=l+r>>1]>=se[i].l) r=md;else l=md+1;
	cnt=0;for(int i=1;i<=m;++i) if(!vis[i]) se[++cnt]=se[i];
	if(!(m=cnt)){printf("0\n");return;}
	for(int i=1,j=m,$;i<j;++i,--j)
		$=se[i].l,se[i].l=se[j].l,se[j].l=$,$=se[i].r,se[i].r=se[j].r,se[j].r=$;
	int l,r=0,lst=1;
	for(;r<m&&se[r+1].r<a[1];++r);
	f[0].clear();f[0].push_back(0);for(int i=1;i<=r;++i) f[0].push_back(inf*1ll*inf);
	a[0]=-inf;a[n+1]=inf;
	for(int i=1;i<=n;lst=l,++i){
		for(l=r+1;r<m&&se[r+1].r<a[i+1];++r);
		f[i].resize(r-l+2);
		g[lst-1]=inf*1ll*inf;for(int j=lst;j<l;++j) g[j]=Min(g[j-1],f[i-1][j-lst]-se[j].r);
		for(int j=0,b,$=l,_=f[i-1][l-lst]-2*a[i];j<=r-l+1;++j){
			if(j) b=se[l+j-1].l-a[i];else b=0;
			for(;$>lst&&a[i]-se[$-1].r<b;--$,_=Min(_,f[i-1][$-lst]-2*se[$].r));
			f[i][j]=Min(b+_+2*a[i],2*b+a[i]+g[$-1]);
		}
	}
	printf("%lld\n",f[n][r-l+1]);
}
signed main(){for(read(T);T--;) slv();return 0;}