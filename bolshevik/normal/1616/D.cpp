#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;const long long inf=1e18;
int T,n,x,ans,s[o],lg[o];long long a[o],st[o][20];
void build(int id,int l,int r){
	s[id]=0;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
void modify(int id,int pos,int l=1,int r=n){
	++s[id];
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,l,md);
	else modify((id<<1)|1,pos,md+1,r);
}
int query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return s[id];
	int md=l+r>>1;
	return (ql<=md?query(id<<1,ql,qr,l,md):0)+(md<qr?query((id<<1)|1,ql,qr,md+1,r):0);
}
inline long long ask(int l,int r){int t=lg[r-l+1];return max(st[l][t],st[r-(1<<t)+1][t]);}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&n);ans=n;build(1,1,n);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		scanf("%d",&x);lg[0]=-1;
		for(int i=1;i<=n;++i) a[i]+=a[i-1]-x;
		for(int i=0;i<=n;++i) st[i][0]=a[i];
		for(int i=1;i<=n+1;++i) lg[i]=lg[i>>1]+1;
		for(int i=1;i<20;++i) for(int j=0;j<=n;++j)
			st[j][i]=max(st[j][i-1],(j+(1<<(i-1))<=n)?st[j+(1<<(i-1))][i-1]:-inf);
		for(int i=2,l,r,md;i<=n;++i){
			for(l=-1,r=i-2;l<r;) if(ask(md=(l+r>>1)+1,i-2)>a[i]) l=md;else r=md-1;
			if(l>=0) if(!query(1,l+1,i)) modify(1,i),--ans;
		}
	}
	return 0;
}