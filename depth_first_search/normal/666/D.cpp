#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
using namespace std;
int ans,x[4],y[4],sx[4],sy[4],gx[4],gy[4],ox[4],oy[4],id[9];map<int,int> cx,cy;
int u[4];I void Match(CI i=0,CI t=0)
{
	if(t>=ans) return;if(i==4) {for(RI j=0;j^4;++j) sx[j]=ox[j],sy[j]=oy[j];return (void)(ans=t);}
	for(RI j=0;j^4;++j) !u[j]&&(u[j]=1,ox[j]=gx[i],oy[j]=gy[i],
		(x[j]==gx[i]||y[j]==gy[i])&&(Match(i+1,max(t,abs(x[j]-gx[i])+abs(y[j]-gy[i]))),0),u[j]=0);
}
int kx[2],ky[2];I void dfs(CI i,RI tx=0,RI ty=0)
{
	#define T(x) (x&-x)
	#define P(x) (x^T(x))
	#define Work(x0,y0,x1,y1,x2,y2,x3,y3) (gx[0]=x0,gy[0]=y0,gx[1]=x1,gy[1]=y1,gx[2]=x2,gy[2]=y2,gx[3]=x3,gy[3]=y3,Match())
	if(i==4)
	{
		RI d;if(tx==1&&ty==1) return;if(tx==2&&ty==2)
		{
			abs(kx[0]-kx[1])==abs(ky[0]-ky[1])&&(Work(kx[0],ky[0],kx[0],ky[1],kx[1],ky[0],kx[1],ky[1]),0);return;
		}
		if(ty==1) return d=abs(kx[0]-kx[1]),
			Work(kx[0],ky[0],kx[1],ky[0],kx[0],ky[0]+d,kx[1],ky[0]+d),Work(kx[0],ky[0],kx[1],ky[0],kx[0],ky[0]-d,kx[1],ky[0]-d);
		if(tx==1) return d=abs(ky[0]-ky[1]),
			Work(kx[0],ky[0],kx[0],ky[1],kx[0]+d,ky[0],kx[0]+d,ky[1]),Work(kx[0],ky[0],kx[0],ky[1],kx[0]-d,ky[0],kx[0]-d,ky[1]);
		if(!ty)
		{
			int tmp[4]={y[id[T(cx[kx[0]])]],y[id[P(cx[kx[0]])]],y[id[T(cx[kx[1]])]],y[id[P(cx[kx[1]])]]};
			tmp[0]>tmp[1]&&(swap(tmp[0],tmp[1]),0),tmp[2]>tmp[3]&&(swap(tmp[2],tmp[3]),0),
			d=abs(kx[0]-kx[1]),tmp[1]-=d,tmp[3]-=d,sort(tmp,tmp+4);RI t=tmp[0]+tmp[3]>>1;
			return Work(kx[0],t,kx[1],t,kx[0],t+d,kx[1],t+d);
		}
		if(!tx)
		{
			int tmp[4]={x[id[T(cy[ky[0]])]],x[id[P(cy[ky[0]])]],x[id[T(cy[ky[1]])]],x[id[P(cy[ky[1]])]]};
			tmp[0]>tmp[1]&&(swap(tmp[0],tmp[1]),0),tmp[2]>tmp[3]&&(swap(tmp[2],tmp[3]),0),
			d=abs(ky[0]-ky[1]),tmp[1]-=d,tmp[3]-=d,sort(tmp,tmp+4);RI t=tmp[0]+tmp[3]>>1;
			return Work(t,ky[0],t,ky[1],t+d,ky[0],t+d,ky[1]);
		}
	}
	if(!P(cx[x[i]])&&(cx[x[i]]||tx^2)) !cx[x[i]]&&(kx[tx++]=x[i]),cx[x[i]]^=1<<i,dfs(i+1,tx,ty),!(cx[x[i]]^=1<<i)&&--tx;
	if(!P(cy[y[i]])&&(cy[y[i]]||ty^2)) !cy[y[i]]&&(ky[ty++]=y[i]),cy[y[i]]^=1<<i,dfs(i+1,tx,ty),!(cy[y[i]]^=1<<i)&&--ty;
}
int main()
{
	RI Tt,i;for(scanf("%d",&Tt),i=0;i^4;++i) id[1<<i]=i;W(Tt--)
	{
		for(i=0;i^4;++i) scanf("%d%d",x+i,y+i);if(ans=1e9,dfs(0),ans==1e9) {puts("-1");continue;};
		for(printf("%d\n",ans),i=0;i^4;++i) printf("%d %d\n",sx[i],sy[i]);
	}return 0;
}