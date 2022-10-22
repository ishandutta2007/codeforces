#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 2000
using namespace std;
int n;char s[N+5][N+5];
int main()
{
	RI Tt,i,j,k,Mn,Mx,x0,x1,y0,y1,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) scanf("%s",s[i]+1);
		for(k='0';k<='9';++k)
		{
			for(x0=x1=0,i=1;i<=n;++i) for(j=1;j<=n;++j) s[i][j]==k&&(!x0&&(x0=i),x1=i);
			for(y0=y1=0,j=1;j<=n;++j) for(i=1;i<=n;++i) s[i][j]==k&&(!y0&&(y0=j),y1=j);
			if(t=0,x0==x1&&y0==y1) {printf("0 ");continue;}
			for(i=1;i<=n;++i)
			{
				for(Mn=Mx=0,j=1;j<=n;++j) s[i][j]==k&&(!Mn&&(Mn=j),Mx=j);
				t=max(t,(Mx-Mn)*max(i-1,n-i));
			}
			for(j=1;j<=n;++j)
			{
				for(Mn=Mx=0,i=1;i<=n;++i) s[i][j]==k&&(!Mn&&(Mn=i),Mx=i);
				t=max(t,(Mx-Mn)*max(j-1,n-j));
			}
			for(i=1;i<=n;++i) for(j=1;j<=n;++j) s[i][j]==k&&
				(t=max(t,max(i-1,n-i)*max(j-y0,y1-j)),t=max(t,max(j-1,n-j)*max(i-x0,x1-i)));
			printf("%d ",t);
		}putchar('\n');
	}return 0;
}