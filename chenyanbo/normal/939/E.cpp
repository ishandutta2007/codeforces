#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 500050
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int n,l,r,m1,m2,q,x,op,a[N],tot;
long long s[N];
double ans,c1,c2;
int main()
{
	q=read();
	while(q--){
		op=read();
		if(op==1)
		{
			x=read();
			a[++tot]=x;
			s[tot]=s[tot-1]+x;
			continue;
		}
		n=tot-1; 
		if(!n)
		{
		    printf("%.7lf\n",0);
		    continue;
		}
		
		ans=a[tot];l=1; r=n;
		while(1)
		{
			if(r-l<=5){
				for(int i=l; i<=r; ++i)
				{
					ans=min(ans,(double)(s[i]+a[tot])/(i+1));
				}
				break;
			}
			m1=l+(r-l)/3;
			m2=l+(r-l)/3*2;  //r-l+1
			c1=(double)(s[m1]+a[tot])/(m1+1);
			c2=(double)(s[m2]+a[tot])/(m2+1);
			if(c1<c2){
				ans=min(ans,c1);
			    r=m2-1; 
			}else 
			{
				ans=min(ans,c2);
			    l=m1+1;  
			}
		}
		printf("%.7lf\n",(double)a[tot]-ans);
	}
}