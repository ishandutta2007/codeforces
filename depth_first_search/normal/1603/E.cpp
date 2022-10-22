#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200
using namespace std;
int n,X,Ic[N+5],p[(N+1)*(N+1)+5],f[(N+1)*(N+1)+5][N+5],g[N+5][N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j,k,l,mn,lim;if(scanf("%d%d",&n,&X),n==1) return printf("%d\n",2%X),0;
	RI Fc=1;for(i=1;i<=n;++i) Fc=1LL*Fc*i%X;for(Ic[i=n]=QP(Fc,X-2);i;--i) Ic[i-1]=1LL*Ic[i]*i%X;
	for(i=n+1;i;--i) for(j=0;j<=n;++j) g[i][j]=j<=i?j*i:i*i+g[i+1][j-i];
	RI m,w,v,t=0;for(mn=n^1?2:1;mn<=n+1;++mn)
	{
		for(lim=(mn-1)*(n+1),j=0;j<=lim;++j) for(p[j]=k=0;k<=n;++k) f[j][k]=0;
		for(f[0][0]=p[m=0]=1,i=mn;i<=n+1;++i)
		{
			for(j=m;~j;--j) if(p[j]) for(k=(j+i-2)/(i-1);k^n;++k) if(v=f[j][k])
			{
				if(j+g[i][n-1-k]>lim) continue;
				for(w=min(min(i,n-k),(mn*i-j)/i),l=1;l<=w;++l)
					f[j+i*l][k+l]=(f[j+i*l][k+l]+1LL*v*Ic[l])%X,m=max(m,j+i*l),p[j+i*l]=1;
			}
			i==mn&&(f[0][0]=p[0]=0);
		}
		for(lim+=n+1,j=0;j<=lim;++j) t=(t+f[j][n])%X;
	}return printf("%d\n",(int)(1LL*t*Fc%X)),0;
}