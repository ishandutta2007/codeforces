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
#define DB long double
#define LL long long
#define pb push_back
using namespace std;
int k,n,m,a[N+5],op[N+5];
struct Data
{
	int p;DB x;I Data(CI i=0,DB a=0):p(i),x(a){}
	I bool operator < (Con Data& o) Con {return x>o.x;}
}A[N+5];vector<Data> B[N+5],C;vector<Data>::iterator it;
I bool cmp(Con Data& x,Con Data& y) {return op[x.p]<op[y.p];}
int main()
{
	RI i,x,y;for(scanf("%d%d%d",&k,&n,&m),i=1;i<=k;++i) scanf("%d",a+i),A[i].x=a[i];
	for(i=1;i<=n;++i) scanf("%d%d%d",op+i,&x,&y),
		op[i]==1?(A[x].x<y&&(A[x]=Data(i,y),0)):((op[i]==2?B[x]:C).pb(Data(i,y)),0);
	for(i=1;i<=k;++i) A[i].p&&(B[i].pb(Data(A[i].p,A[i].x-a[i])),0);
	LL t;for(i=1;i<=k;++i) for(sort(B[i].begin(),B[i].end()),t=a[i],
		it=B[i].begin();it!=B[i].end();++it) C.pb(Data(it->p,(t+it->x)/t)),t+=it->x;
	sort(C.begin(),C.end()),C.resize(m=min(m,(int)C.size())),sort(C.begin(),C.end(),cmp);
	for(printf("%d\n",m),it=C.begin();it!=C.end();++it) printf("%d ",it->p);return 0;
}