#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;return a;
    }    
    int ret=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ret;
}
int excrt(int AA,int BB,int CC,int DD)
{
    int M=AA,R=BB,x,y,d;
    d=exgcd(M,CC,x,y);
    if((R-DD)%d) return -1;
    x=(R-DD)/d*x%CC;
    R-=M*x;
    M=M/d*CC;
    R%=M;
    return (R%M+M)%M;
}
signed main()
{
	int n=read(),m=read();
	int x=read(),y=read();
	if((x==0||x==n)&&(y==0||y==m))
	{
		printf("%lld %lld\n",x,y);
		return 0;
	}
	int dx=read(),dy=read();
	int ans=1000000000000000000ll,tx=-1,ty=-1;
	int xto0,xton,yto0,ytom;
	//loop:2n
	if(dx==1) xton=n-x,xto0=n+n-x;
	else if(dx==-1) xto0=x,xton=n+x;
	else xto0=(x==0?-1:-2),xton=(x==n?-1:-2);
	if(dy==1) ytom=m-y,yto0=m+m-y;
	else if(dy==-1) yto0=y,ytom=m+y;
	else yto0=(y==0?-1:-2),ytom=(y==m?-1:-2);
	//(0,0)
	int A;
	if(xto0!=-2&&yto0!=-2)
	{
		if(xto0==-1) A=yto0;
		else if(yto0==-1) A=xto0;
		else A=excrt(n<<1,xto0,m<<1,yto0);
		if(A!=-1&&A<ans) ans=A,tx=0,ty=0;
	}
	//(0,m)
	if(xto0!=-2&&ytom!=-2)
	{
		if(xto0==-1) A=ytom;
		else if(ytom==-1) A=xto0;
		else A=excrt(n<<1,xto0,m<<1,ytom);
		if(A!=-1&&A<ans) ans=A,tx=0,ty=m;
	}
	//(n,0)
	if(xton!=-2&&yto0!=-2)
	{
		if(xton==-1) A=yto0;
		else if(yto0==-1) A=xton;
		else A=excrt(n<<1,xton,m<<1,yto0);
		if(A!=-1&&A<ans) ans=A,tx=n,ty=0;
	}
	//(n,m)
	if(xton!=-2&&ytom!=-2)
	{
		if(xton==-1) A=ytom;
		else if(ytom==-1) A=xton;
		else A=excrt(n<<1,xton,m<<1,ytom);
		if(A!=-1&&A<ans) ans=A,tx=n,ty=m;
	}
	if(tx==-1) puts("-1");
	else printf("%lld %lld\n",tx,ty);
    return 0;
}