#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int main()
{
	for(int T=read(); T--;)
	{
		int n=read(),l=read();
		for(int i=1; i<=n; i++) a[i]=read();
		a[++n]=l;
		int L=0,R=n,x=1,y=1;
		double t1=0,t2=0;
		while(L+1<R)
		{
			if(t1+1.0*(a[L+1]-a[L])/x<t2+1.0*(a[R]-a[R-1])/y) t1+=1.0*(a[L+1]-a[L++])/x,++x;
			else t2+=1.0*(a[R]-a[--R])/y,++y;
		}
		if(t1>t2) printf("%.10lf\n",t1+((double)a[R]-(double)a[L]-(t1-t2)*y)/(double)(x+y));
		else printf("%.10lf\n",t2+((double)a[R]-(double)a[L]-(t2-t1)*x)/(double)(x+y));
	}
    return 0;
}