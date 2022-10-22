#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
inline int lowbit(int x){return x&-x;}
#define fi first
#define se second
const int o=2e5+10,inf=1e8;
int n,m,x,lg[o],a[o],b[o],na[o],nb[o],st[2][o][20],st2[2][o][20],lo[o],hi[o],ft[o];pair<int,int> p1[o],p2[o];long long ans;
inline int query(int id,int l,int r){int t=lg[r-l+1];return Min(st[id][l][t],st[id][r-(1<<t)+1][t]);}
int query2(int id,int l,int r){if(!l||r>(id?m:n)) return inf;int t=lg[r-l+1];return Max(st2[id][l][t],st2[id][r-(1<<t)+1][t]);}
inline bool cmp1(pair<int,int> A,pair<int,int> B){return A.se<B.se;}
inline bool cmp2(pair<int,int> A,pair<int,int> B){return A.fi>B.fi;}
inline void modify(int pos){for(++pos;pos<o;pos+=lowbit(pos)) ++ft[pos];}
inline int ask(int pos){if(++pos<0) return 0;int res=0;for(;pos;pos-=lowbit(pos)) res+=ft[pos];return res;}
int main(){
	read(n);read(m);read(x);lg[0]=-1;
	for(int i=1;i<=n;++i) read(a[i]),st[0][i][0]=st2[0][i][0]=a[i],lg[i]=lg[i>>1]+1;
	for(int i=1;i<=m;++i) read(b[i]),st[1][i][0]=st2[1][i][0]=b[i],lg[i]=lg[i>>1]+1;
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j)
		st[0][j][i]=Min(st[0][j][i-1],(j+(1<<(i-1))>n)?inf:st[0][j+(1<<(i-1))][i-1]),
		st2[0][j][i]=Max(st2[0][j][i-1],(j+(1<<(i-1))>n)?0:st2[0][j+(1<<(i-1))][i-1]);
	for(int i=1;i<20;++i) for(int j=1;j<=m;++j)
		st[1][j][i]=Min(st[1][j][i-1],(j+(1<<(i-1))>m)?inf:st[1][j+(1<<(i-1))][i-1]),
		st2[1][j][i]=Max(st2[1][j][i-1],(j+(1<<(i-1))>m)?0:st2[1][j+(1<<(i-1))][i-1]);
	for(int i=1,l,r,md;i<=n;lo[i++]=l) for(l=0,r=i-1;l<r;) if(query(0,md=(l+r>>1)+1,i)<a[i]) l=md;else r=md-1;
	for(int i=1,l,r,md;i<=n;hi[i++]=l) for(l=i+1,r=n+1;l<r;) if(query(0,i+1,md=l+r>>1)<=a[i]) r=md;else l=md+1;
	for(int i=1;i<=n;++i) na[i]=Min(query2(0,lo[i],i),query2(0,i,hi[i]));
	for(int i=1,l,r,md;i<=m;lo[i++]=l) for(l=0,r=i-1;l<r;) if(query(1,md=(l+r>>1)+1,i)<b[i]) l=md;else r=md-1;
	for(int i=1,l,r,md;i<=m;hi[i++]=l) for(l=i+1,r=m+1;l<r;) if(query(1,i+1,md=l+r>>1)<=b[i]) r=md;else l=md+1;
	for(int i=1;i<=m;++i) nb[i]=Min(query2(1,lo[i],i),query2(1,i,hi[i]));
	for(int i=1;i<=n;++i) p1[i]=make_pair(na[i],a[i]);
	for(int i=1;i<=m;++i) p2[i]=make_pair(nb[i],b[i]);
	sort(p1+1,p1+1+n,cmp1);sort(p2+1,p2+1+m,cmp2);
	for(int i=1,j=1;i<=n;ans+=ask(x-p1[i].se)-ask(x-p1[i].fi),++i) for(;j<=m&&p1[i].se+p2[j].fi>x;modify(p2[j++].se));
	printf("%lld",ans);
	return 0;
}