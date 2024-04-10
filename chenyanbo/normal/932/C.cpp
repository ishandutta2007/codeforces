
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline long long read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

long long uu,p[10000050],r,x,y,a,b,n,h,xx,yy,zz,u,v;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if(!b){
		x=1;
		y=0;
		return a;
	}
	//int = ll //dou =int +0.40.50.6
	long long r=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return r;
}

int main()
{
	n=read();a=read();b=read();
	r=exgcd(a,b,x,y);
	if(n%r){
		puts("-1");
		return 0;
	}
	h=n/r;
	xx=x*h;
	yy=y*h; 
	
	
	a/=r;
	b/=r;
	
	if(xx<0){
		uu=(-xx-1)/b+1;   ///a/r   b/r
		xx+=uu*b;
		yy-=uu*a;
	}
	
	if(yy<0){
		uu=(-yy-1)/a+1;
		yy+=uu*a;
		xx-=uu*b;
	}
	
	if(xx<0){
		puts("-1");
		exit(0);
	}
	
	a*=r;
	b*=r;
	
	u=1;
	for(int i=1; i<=xx; ++i){
		v=u+a-1;
		for(int j=u; j<=v; ++j)  
		{
			p[j]=j+1;
		}
		p[v]=u;
		u+=a;
	}
	
	for(int i=1; i<=yy; ++i){
		v=u+b-1;
		for(int j=u; j<=v; ++j)  
		{
			p[j]=j+1;
		}
		p[v]=u;
		u+=b;
	}
// l l d  d  //<-> //zhengchang //
	for(int i=1; i<=n; ++i)printf("%d ",p[i]);

}