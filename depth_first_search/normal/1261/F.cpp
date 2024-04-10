#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100
#define LG 60
#define LL long long
#define Pr pair<LL,LL> 
#define mp make_pair
#define fi first
#define se second
#define X 998244353
#define I2 499122177
using namespace std;
vector<Pr> S,a[LG+1],b[LG+1],A[LG+1],B[LG+1];vector<Pr>::iterator it,jt;
I int Calc(Cn LL& l,Cn LL& r) {return 1LL*((l+r)%X)*((r-l+1)%X)%X*I2%X;}
I void Split(vector<Pr>* v,vector<Pr>* V,LL L,LL R,Cn LL& l=0,Cn LL& r=(1LL<<60)-1,CI d=0)
{
	if(V[d].push_back(mp(l,r)),L<=l&&r<=R) return (void)v[d].push_back(mp(l,r));LL mid=l+r>>1;
	L<=mid&&(Split(v,V,L,R,l,mid,d+1),0),R>mid&&(Split(v,V,L,R,mid+1,r,d+1),0);
}
int main()
{
	RI n;LL x,y;scanf("%d",&n);W(n--) scanf("%lld%lld",&x,&y),Split(a,A,x,y);scanf("%d",&n);W(n--) scanf("%lld%lld",&x,&y),Split(b,B,x,y);
	RI i;for(i=0;i<=LG;++i)
	{
		for(it=a[i].begin();it!=a[i].end();++it) for(jt=B[i].begin();jt!=B[i].end();++jt) S.push_back(mp(it->fi^jt->fi,it->fi^jt->se));
		for(it=A[i].begin();it!=A[i].end();++it) for(jt=b[i].begin();jt!=b[i].end();++jt) S.push_back(mp(it->fi^jt->fi,it->fi^jt->se));
	}
	LL t=0,k=0;for(sort(S.begin(),S.end()),it=S.begin();it!=S.end();++it) it->se>=k&&(t=(t+Calc(max(k,it->fi),it->se))%X,k=it->se+1);return printf("%lld\n",t),0;
}