#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
using namespace std;
int n;vector<int> v[N+5];vector<int>::iterator it;
class SegmentTree
{
	private:
		#define PT CI l=0,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		int Mn[N<<2];
	public:
		I void Build(PT) {if(Mn[rt]=n+1,l==r) return;RI mid=l+r>>1;Build(LT),Build(RT);}
		I void U(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)(Mn[rt]=min(Mn[rt],v));
			RI mid=l+r>>1;L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0);
		}
		I int Q(CI x,PT)
		{
			if(l==r) return Mn[rt];RI mid=l+r>>1;return min(Mn[rt],x<=mid?Q(x,LT):Q(x,RT));
		}
}S;
int main()
{
	RI i,x;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&x),x<=n+2&&(v[x].push_back(i),0);
	RI lst,fg;for(S.Build(),i=1;i<=n+2;++i)
	{
		fg=1,lst=0,v[i].push_back(n+1);
		for(it=v[i].begin();it!=v[i].end();lst=*it,++it)
			lst+1<=*it-1&&S.Q(*it-1)>lst&&(fg=0),S.U(lst,*it-1,lst);
		if(fg) return printf("%d\n",i),0;
	}return 0;
}