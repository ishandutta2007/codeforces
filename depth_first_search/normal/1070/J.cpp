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
using namespace std;
int n,m,k,c[30],f[30][N+5];
int main()
{
	RI Tt,i,j,l;long long t;char x;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d%d",&n,&m,&k),memset(c,0,sizeof(c)),i=1;i<=k;++i) cin>>x,++c[x&31];
		for(t=1e18,i=1;i<=26;++i) if(c[i])
		{
			for(f[0][0]=l=1;l<=k;++l) f[0][l]=0;for(j=1;j<=26;++j)
			{
				if(i==j) {for(l=0;l<=k;++l) f[j][l]=f[j-1][l];continue;}
				for(l=0;l<=k;++l) f[j][l]=f[j-1][l]|(l>=c[j]&&f[j-1][l-c[j]]);
			}
			for(l=0;l<=k;++l) if(f[26][l])
			{
				if(l+c[i]<n||k-l<m) continue;if(l>=n||k-l-c[i]>=m) {t=0;continue;}
				t=min(t,1LL*(n-l)*(m-(k-l-c[i])));
			}
		}printf("%lld\n",t);
	}return 0;
}