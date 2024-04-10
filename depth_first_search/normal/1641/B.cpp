#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500
#define SZ 2*N*N
using namespace std;
int n,a[N+5],ct,c[SZ+5],qt;pair<int,int> q[SZ+5];map<int,int> F;
int main()
{
	RI Tt,i,j,k,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),F.clear(),i=1;i<=n;++i) scanf("%d",a+i),F[a[i]]^=1;
		W(!F.empty()&&!F.begin()->second) F.erase(F.begin());if(!F.empty()) {F.clear(),puts("-1");continue;}
		for(t=ct=qt=0,i=1;i<=n;i+=2)
		{
			for(j=i+1;j<=n&&a[i]^a[j];++j);for(k=1;k<j-i;++k) q[++qt]=make_pair(t+j+k-1,a[i+k]);
			for(t+=(c[++ct]=j-i<<1)-2,k=j;k^i;--k) a[k]=a[k-1];reverse(a+i+2,a+j+1);
		}
		for(printf("%d\n",qt),i=1;i<=qt;++i) printf("%d %d\n",q[i].first,q[i].second);
		for(printf("%d\n",ct),i=1;i<=ct;++i) printf("%d%c",c[i]," \n"[i==ct]);
	}return 0;
}