#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define LL long long
using namespace std;
int n;LL a[N+5];map<LL,LL> P;map<LL,LL>::iterator it;
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%lld",a+i);
	for(P[a[1]-1]=0,i=2;i<=n;++i) for(it=P.lower_bound(a[i]);it!=P.end();P.erase(it++))
		P[it->first%a[i]]=max(P[it->first%a[i]],it->second+(i-1)*(it->first-it->first%a[i])),
		P[a[i]-1]=max(P[a[i]-1],it->second+(i-1)*((it->first-(a[i]-1))/a[i]*a[i]));
	LL t=0;for(it=P.begin();it!=P.end();++it) t=max(t,n*it->first+it->second);return printf("%lld\n",t),0;
}