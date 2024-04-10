#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define NM 10100000
#define N 100000
#define F(x,y) f[(x)*m+(y)]
#define Gmax(x,y) (x<(y)&&(x=(y)))
using namespace std;
int n,m,nxt[N+5],w[N+5][30],f[NM+5];char A[N+5],B[N+5];
int main()
{
	RI i,j,k;scanf("%s%s",A+1,B+1),n=strlen(A+1),m=strlen(B+1);
	for(i=2,j=0;i<=m;B[j+1]==B[i]&&++j,nxt[i++]=j) W(j&&B[j+1]^B[i]) j=nxt[j];
	for(i=0;i^m;++i) for(j=1;j<=26;++j) w[i][j]=j^(B[i+1]&31)?w[nxt[i]][j]:i+1;
	for(memset(f,-1,sizeof(f)),F(0,0)=0,i=1;i<=n;++i) for(j=0;j^m;++j) if(~F(i-1,j)) for(k=1;k<=26;++k)
		(A[i]=='?'||(A[i]&31)==k)&&(w[j][k]^m?Gmax(F(i,w[j][k]),F(i-1,j)):Gmax(F(i,nxt[m]),F(i-1,j)+1),0);
	RI t=0;for(i=0;i^m;++i) t=max(t,F(n,i));return printf("%d\n",t),0;
}