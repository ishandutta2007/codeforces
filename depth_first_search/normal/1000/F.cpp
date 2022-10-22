#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
using namespace std;
int n,a[2*N+5],lnk[N+5],pre[N+5],nxt[N+5],ans[N+5];struct Q {int p,l,r;I bool operator < (Cn Q& o) Cn {return r<o.r;}}q[N+5];
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		int V[N<<2];
	public:
		I void U(CI L,CI R,CI v,PT) {if(L<=l&&r<=R) return (void)(V[rt]=max(V[rt],v));RI mid=l+r>>1;L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0);}
		I int Q(CI x,PT) {if(l==r) return V[rt];RI mid=l+r>>1;return max(x<=mid?Q(x,LT):Q(x,RT),V[rt]);}
}S;
int main()
{
	RI Qt,i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(scanf("%d",&Qt),i=1;i<=Qt;++i) scanf("%d%d",&q[i].l,&q[i].r),q[i].p=i;sort(q+1,q+Qt+1);
	RI ct=n;for(i=1;i<=n;++i) (pre[i]=lnk[a[i]])&&(nxt[pre[i]]=i),lnk[a[i]]=i;for(i=1;i<=N;++i) lnk[i]&&(a[nxt[lnk[i]]=++ct]=i);
	RI j,x;for(i=j=1;i<=n;++i) {S.U(pre[i]+1,i,nxt[i]);W(j<=Qt&&q[j].r==i) (x=S.Q(q[j].l))>q[j].r&&(ans[q[j].p]=a[x]),++j;}
	for(i=1;i<=Qt;++i) printf("%d\n",ans[i]);return 0;
}