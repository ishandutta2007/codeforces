#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg //register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,l,g[N+5],L[N+5],R[N+5];char s[2*N+5];
namespace SuffixArray
{
	int t[2*N+5],p[2*N+5],rk[2*N+5],SA[2*N+5];
	I void Sort(CI S)
	{
		RI i;for(i=0;i<=S;++i) t[i]=0;for(i=1;i<=n;++i) ++t[rk[i]];
		for(i=1;i<=S;++i) t[i]+=t[i-1];for(i=n;i;--i) SA[t[rk[p[i]]]--]=p[i];
	}
	I void GetSA()
	{
		RI i,j,k,c=0,S=')';for(i=1;i<=n;++i) rk[p[i]=i]=s[i];for(Sort(S),k=1;c^n;k<<=1,S=c)
		{
			for(c=0,i=1;i<=k;++i) p[++c]=n-k+i;for(i=1;i<=n;++i) SA[i]>k&&(p[++c]=SA[i]-k);for(Sort(S),i=1;i<=n;++i) p[i]=rk[i];
			for(c=rk[SA[1]]=1,i=2;i<=n;++i) (p[SA[i-1]]^p[SA[i]]||p[SA[i-1]+k]^p[SA[i]+k])&&++c,rk[SA[i]]=c;
		}
	}
}using namespace SuffixArray;
int main()
{
	RI i;for(scanf("%s",s+1),l=strlen(s+1),i=1;i<=l;++i) g[i]=g[i-1]+(s[i]=='('?1:-1),s[l+i]=s[i];n=l<<1,GetSA();
	for(L[0]=1e9,i=1;i<=l;++i) L[i]=min(L[i-1],g[i]);for(R[l+1]=1e9,i=l;i;--i) R[i]=min(R[i+1],g[i]);
	RI x,o,w,t=1e9;for(i=1;i<=n;++i) if((x=SA[i])<=l) (o=-min(min(R[x]-g[x-1],g[l]-g[x-1]+L[x-1]),0))<t&&(w=x,t=o);
	for(i=1;i<=t;++i) putchar('(');if((t+=g[l])<0) for(i=1;i<=-t;++i) putchar('(');
	for(i=w;i<w+l;++i) putchar(s[i]);if(t>0) for(i=1;i<=t;++i) putchar(')');return 0;
}