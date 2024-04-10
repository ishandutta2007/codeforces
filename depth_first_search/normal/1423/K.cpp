#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,Pt,P[N+5],s[N+5];I void Sieve()
{
	for(RI i=2,j;i<=N;++i) for(!P[i]&&(s[P[++Pt]=i]=1),j=1;j<=Pt&&i*P[j]<=N;++j) if(P[i*P[j]]=1,!(i%P[j])) break;
	for(RI i=1;i<=N;++i) s[i]+=s[i-1];
}
int main()
{
	RI Tt;Sieve(),scanf("%d",&Tt);W(Tt--) scanf("%d",&n),printf("%d\n",s[n]-s[(int)sqrt(n)]+1);return 0;
}