#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define SZ 550000
#define LN 20
using namespace std;
int n,m,p[SZ+5];char s[SZ+5];
struct Data {int v,p;I Data(CI x=0,CI y=0):v(x),p(y){}
	I bool operator < (Con Data& o) Con {return v^o.v?v<o.v:p>o.p;}};
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=m
		#define LT l,mid
		#define RT mid+1,r
		#define PU(x) (O[x].Mx=max(O[O[x].S[0]].Mx,O[O[x].S[1]].Mx))
		int Nt;struct node {Data Mx;int S[2];}O[SZ*40];
	public:
		I SegmentTree() {O[0].Mx=-1;}
		I void A(int& rt,CI x,PT)
		{
			if(!rt&&(rt=++Nt),l==r) return (void)(++O[rt].Mx.v,O[rt].Mx.p=x);RI mid=l+r>>1;
			x<=mid?A(O[rt].S[0],x,LT):A(O[rt].S[1],x,RT),PU(rt);
		}
		I void Merge(int& x,RI y,PT)
		{
			if(!x||!y) return (void)(x|=y);if(O[++Nt]=O[x],x=Nt,l==r) return (void)(O[x].Mx.v+=O[y].Mx.v);
			RI mid=l+r>>1;Merge(O[x].S[0],O[y].S[0],LT),Merge(O[x].S[1],O[y].S[1],RT),PU(x);
		}
		I Data Q(CI rt,CI L,CI R,PT)
		{
			if(L==l&&r==R) return O[rt].Mx;RI mid=l+r>>1;if(R<=mid) return Q(O[rt].S[0],L,R,LT);
			if(L>mid) return Q(O[rt].S[1],L,R,RT);return max(Q(O[rt].S[0],L,mid,LT),Q(O[rt].S[1],mid+1,R,RT));
		}
}S;
namespace SAM
{
	int Nt=1,lst=1,c[SZ<<1],q[SZ<<1];struct node {int Rt,L,F[LN+1],S[30];}O[SZ<<1];
	I int A(CI x)
	{
		RI p=lst;if(O[p].S[x])
		{
			RI q=O[p].S[x];if(O[q].L==O[p].L+1) return lst=q;RI k=++Nt;
			(O[k]=O[q]).Rt=0,O[k].L=O[p].L+1,O[q].F[0]=k;W(p&&O[p].S[x]==q) O[p].S[x]=k,p=O[p].F[0];return lst=k;
		}
		RI o=lst=++Nt;O[o].L=O[p].L+1;W(p&&!O[p].S[x]) O[p].S[x]=o,p=O[p].F[0];if(!p) return O[o].F[0]=1,o;
		RI q=O[p].S[x];if(O[q].L==O[p].L+1) return O[o].F[0]=q,o;RI k=++Nt;
		(O[k]=O[q]).Rt=0,O[k].L=O[p].L+1,O[q].F[0]=O[o].F[0]=k;W(p&&O[p].S[x]==q) O[p].S[x]=k,p=O[p].F[0];return o;
	}
	I void Work()
	{
		RI i;for(i=1;i<=Nt;++i) ++c[O[i].L];for(i=1;i<=Nt;++i) c[i]+=c[i-1];for(i=1;i<=Nt;++i) q[c[O[i].L]--]=i;
		RI j;for(i=2;i<=Nt;++i) for(j=1;j<=LN;++j) O[q[i]].F[j]=O[O[q[i]].F[j-1]].F[j-1];
		for(i=Nt;i^1;--i) S.Merge(O[O[q[i]].F[0]].Rt,O[q[i]].Rt);
	}
	I int Jump(RI x,CI l) {for(RI i=LN;~i;--i) O[O[x].F[i]].L>=l&&(x=O[x].F[i]);return x;}
	I void Q(CI x,CI l,CI r) {Data t=S.Q(O[x].Rt,l,r);t.p?printf("%d %d\n",t.p,t.v):printf("%d 0\n",l);}
}
int main()
{
	RI Qt,i,j,l,r,x,y;for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;++i) p[i]=SAM::A(s[i]&31);
	for(scanf("%d",&m),i=1;i<=m;++i) for(scanf("%s",s+1),
		l=strlen(s+1),SAM::lst=j=1;j<=l;++j) S.A(SAM::O[SAM::A(s[j]&31)].Rt,i);
	SAM::Work(),scanf("%d",&Qt);W(Qt--) scanf("%d%d%d%d",&l,&r,&x,&y),SAM::Q(SAM::Jump(p[y],y-x+1),l,r);return 0;
}