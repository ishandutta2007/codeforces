#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
using namespace std;
int n,p[N+5];
struct Hash
{
	#define ull unsigned long long
	#define CU Con ull&
	ull x,y;I Hash() {x=y=0;}I Hash(CU a) {x=y=a;}I Hash(CU a,CU b):x(a),y(b){}
	I Hash operator + (Con Hash& o) Con {return Hash(x+o.x,y+o.y);}
	I Hash operator - (Con Hash& o) Con {return Hash(x-o.x,y-o.y);}
	I Hash operator * (Con Hash& o) Con {return Hash(x*o.x,y*o.y);}
	I bool operator != (Con Hash& o) Con {return x^o.x||y^o.y;}
}seed(19,302627441),P[N+5];
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (A[x]=A[x<<1]*P[r-mid]+A[x<<1|1],B[x]=B[x<<1]+B[x<<1|1]*P[mid-l+1])
		Hash A[N<<2],B[N<<2];
	public:
		I void U(CI x,PT)
		{
			if(l==r) return (void)(A[rt]=B[rt]=1);RI mid=l+r>>1;
			x<=mid?U(x,LT):U(x,RT),PU(rt);
		}
		I Hash QA(CI L,CI R,PT)
		{
			if(L==l&&r==R) return A[rt];RI mid=l+r>>1;if(R<=mid) return QA(L,R,LT);
			if(L>mid) return QA(L,R,RT);return QA(L,mid,LT)*P[R-mid]+QA(mid+1,R,RT);
		}
		I Hash QB(CI L,CI R,PT)
		{
			if(L==l&&r==R) return B[rt];RI mid=l+r>>1;if(R<=mid) return QB(L,R,LT);
			if(L>mid) return QB(L,R,RT);return QB(L,mid,LT)+QB(mid+1,R,RT)*P[mid-L+1];
		}
}S;
int main()
{
	RI i;for(scanf("%d",&n),P[0]=i=1;i<=n;++i) scanf("%d",p+i),P[i]=P[i-1]*seed;
	RI t;for(i=1;i<=n;S.U(p[i]),++i) if(t=min(p[i]-1,n-p[i]))
		if(S.QA(p[i]-t,p[i]-1)!=S.QB(p[i]+1,p[i]+t)) return puts("YES");
	return puts("NO"),0;
}