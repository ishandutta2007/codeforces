#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define S 500
#define N 16
#define X 1000000007
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,m,l,f[S+5][1<<N],v[5];char s[S+5];
I void FWT_A(int *s,CI op)
{
	RI i,j,k;for(i=1;i<=m;i<<=1) for(j=0;j<=m;j+=i<<1)
		for(k=0;k^i;++k) op?Inc(s[j+k],s[i+j+k]):Inc(s[j+k],X-s[i+j+k]);
}
I void FWT_O(int *s,CI op)
{
	RI i,j,k;for(i=1;i<=m;i<<=1) for(j=0;j<=m;j+=i<<1)
		for(k=0;k^i;++k) op?Inc(s[i+j+k],s[j+k]):Inc(s[i+j+k],X-s[j+k]);
}
I void Mul_A(CI x,CI lc,CI rc)
{
	FWT_A(f[x],1),FWT_A(f[lc],1),FWT_A(f[rc],1);
	for(RI i=0;i<=m;++i) f[x][i]=(1LL*f[lc][i]*f[rc][i]+f[x][i])%X;
	FWT_A(f[x],0),FWT_A(f[lc],0),FWT_A(f[rc],0);
}
I void Mul_O(CI x,CI lc,CI rc)
{
	FWT_O(f[x],1),FWT_O(f[lc],1),FWT_O(f[rc],1);
	for(RI i=0;i<=m;++i) f[x][i]=(1LL*f[lc][i]*f[rc][i]+f[x][i])%X;
	FWT_O(f[x],0),FWT_O(f[lc],0),FWT_O(f[rc],0);
}
int cur,tot;I int DP()
{
	RI x=++tot;if(s[cur+2]==')')
	{
		if(s[cur+1]=='?') for(RI i=0;i^4;++i) ++f[tot][v[i]],++f[tot][v[i]^m];
		else (s[cur+1]<='D'?f[tot][v[s[cur+1]-'A']]:f[tot][v[s[cur+1]-'a']^m])=1;
		return cur+=3,x;
	}
	RI lc,rc;char op;++cur,lc=DP(),op=s[cur],++cur,rc=DP();
	return op^'|'&&(Mul_A(x,lc,rc),0),op^'&'&&(Mul_O(x,lc,rc),0),++cur,x;
}
int main()
{
	RI i,j,x;scanf("%s%d",s+1,&n),l=strlen(s+1),s[0]='(',s[l+1]=')';
	for(m=(1<<n)-1,i=0;i^n;++i) for(j=0;j^5;++j) scanf("%d",&x),v[j]|=x<<i;
	if(!n) {for(DP(),x=i=0;i<=m;++i) Inc(x,f[1][i]);return printf("%d\n",x),0;}
	return printf("%d\n",f[DP()][v[4]]),0;
}