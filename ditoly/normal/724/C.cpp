#include<cstdio>
#define ll long long
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
ll exgcd(ll a,ll b,ll&x,ll&y,ll z)
{
	ll g,xx,yy;
	if(b)
	{
		int g=exgcd(b,a%b,xx,yy,z);
		if(g)x=-yy,y=-xx-a/b*yy;
		return g;
	}
	else
	{
		if(z%a)return 0;
		x=z/a;y=0;
		return a;
	}
}
int main()
{
	ll n,m,k,x,y,g,a,b,t,ans;
	n=read()<<1;m=read()<<1;k=read();
	while(k--)
	{
		x=read();y=read();ans=-1;
		g=exgcd(n,m,a,b,-x+y);
		if(g){g=n*m/g;t=n*a+x;t%=g;if(t<0)t+=g;if(ans<0||t<ans)ans=t;}
		g=exgcd(n,m,a,b, x+y);
		if(g){g=n*m/g;t=n*a-x;t%=g;if(t<0)t+=g;if(ans<0||t<ans)ans=t;}
		g=exgcd(n,m,a,b,-x-y);
		if(g){g=n*m/g;t=n*a+x;t%=g;if(t<0)t+=g;if(ans<0||t<ans)ans=t;}
		g=exgcd(n,m,a,b, x-y);
		if(g){g=n*m/g;t=n*a-x;t%=g;if(t<0)t+=g;if(ans<0||t<ans)ans=t;}
		printf("%I64d\n",ans);
	}
}