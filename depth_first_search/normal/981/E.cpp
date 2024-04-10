#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 10000
using namespace std;
int n;bitset<N+5> s;class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		bitset<N+5> w[30];vector<int> g[N<<2];
	public:
		I SegmentTree() {w[0].set(0);}
		I void K(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)g[rt].push_back(v);RI mid=l+r>>1;L<=mid&&(K(L,R,v,LT),0),R>mid&&(K(L,R,v,RT),0);
		}
		I void Travel(CI d=0,PT)
		{
			for(vector<int>::iterator it=g[rt].begin();it!=g[rt].end();++it) w[d]|=w[d]<<*it;
			if(l==r) return (void)(s|=w[d]);RI mid=l+r>>1;w[d+1]=w[d],Travel(d+1,LT),w[d+1]=w[d],Travel(d+1,RT); 
		}
}S;
int main()
{
	RI Qt,l,r,x;scanf("%d%d",&n,&Qt);W(Qt--) scanf("%d%d%d",&l,&r,&x),S.K(l,r,x);S.Travel();
	RI i,t=0;for(i=1;i<=n;++i) s.test(i)&&++t;for(printf("%d\n",t),i=1;i<=n;++i) s.test(i)&&printf("%d ",i);return 0;
}