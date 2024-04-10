#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50000
#define LL long long
#define S(x) (U.count(x)?U[x]:s[(x)%n])
using namespace std;
int n,m,X,s[N+5];LL k,q[2*N+5];map<LL,int> U;
struct M
{
	int a[2][2];I M(CI A=0,CI B=0,CI C=0,CI D=0) {a[0][0]=A,a[0][1]=B,a[1][0]=C,a[1][1]=D;}
	I int* operator [] (CI x) {return a[x];}I Con int* operator [] (CI x) Con {return a[x];}
	I M operator * (Con M& o) Con
	{
		M t;t[0][0]=(1LL*a[0][0]*o[0][0]+1LL*a[0][1]*o[1][0])%X;
		t[0][1]=(1LL*a[0][0]*o[0][1]+1LL*a[0][1]*o[1][1])%X;
		t[1][0]=(1LL*a[1][0]*o[0][0]+1LL*a[1][1]*o[1][0])%X;
		t[1][1]=(1LL*a[1][0]*o[0][1]+1LL*a[1][1]*o[1][1])%X;return t;
	}
	I M operator ^ (LL y) Con
	{
		M x=*this,t(1,0,0,1);W(y) y&1&&(t=t*x,0),x=x*x,y>>=1;return t;
	}
};
class SegmentTree
{
	private:
		#define PT CI l=0,CI r=n-1,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		M V[N<<2];
	public:
		I void Build(PT)
		{
			if(l==r) return (void)(V[rt]=M(0,s[(l-2+n)%n],1,s[(l-1+n)%n]));
			RI mid=l+r>>1;Build(LT),Build(RT),V[rt]=V[rt<<1]*V[rt<<1|1];
		}
		I M Q(CI L,CI R,PT)
		{
			if(L>R) return M(1,0,0,1);if(L==l&&r==R) return V[rt];RI mid=l+r>>1;
			if(R<=mid) return Q(L,R,LT);if(L>mid) return Q(L,R,RT);return Q(L,mid,LT)*Q(mid+1,R,RT);
		}
}S;
int main()
{
	RI i;if(scanf("%lld%d",&k,&X),!k) return puts("0"),0;if(k==1) return puts(X^1?"1":"0"),0;
	for(scanf("%d",&n),i=0;i^n;++i) scanf("%d",s+i);S.Build(0,n-1);
	LL x,y;for(scanf("%d",&m),i=1;i<=m;++i) scanf("%lld%lld",&x,&y),U[x]=y,q[i]=x+1,q[m+i]=x+2;
	q[2*m+1]=k,sort(q+1,q+2*m+2),m=unique(q+1,q+2*m+2)-q-1;W(m&&q[m]>k) --m;
	LL nx,ny;M t;t[1][1]=1;for(x=0,y=1,i=1;i<=m;x=nx,y=ny,++i)
		nx=q[i]/n,ny=q[i]%n,y>=ny&&(++x,t=t*S.Q(y+1,n-1)*S.Q(0,ny-1),y=ny-1),
		t=t*((S.Q(y+1,n-1)*S.Q(0,y))^(nx-x))*S.Q(y+1,ny-1)*M(0,S(q[i]-2),1,S(q[i]-1));
	return printf("%d\n",t[1][1]),0;
}