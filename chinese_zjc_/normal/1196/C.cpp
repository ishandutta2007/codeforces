#include<cstdio>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	ddd*=xxx;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int t,n,a,b,c,d,A,B,C,D,x,y;
signed main()
{
	rd(t);
	while(t>0)
	{
		--t;
		rd(n);
		A=-100000;
		B=100000;
		C=100000;
		D=-100000;
		for(int i=1;i<=n;++i)
		{
			rd(x);
			rd(y);
			rd(a);
			rd(b);
			rd(c);
			rd(d);
			if(!a)
			{
				A=max(A,x);
			}
			if(!b)
			{
				B=min(B,y);
			}
			if(!c)
			{
				C=min(C,x);
			}
			if(!d)
			{
				D=max(D,y);
			}
		}
		if(C-A>=0&&B-D>=0)
		{
			printf("1 %lld %lld\n",A,D);
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}