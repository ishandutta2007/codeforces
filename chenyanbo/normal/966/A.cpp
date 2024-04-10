//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 100006
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int d,ans,n,m,cl,ce,v,q,a1,a2,b1,b2,a[N],b[N];

int main()
{
	n=read(); m=read(); cl=read(); ce=read(); v=read();
	for(int i=1; i<=cl; ++i)a[i]=read();
	for(int i=1; i<=ce; ++i)b[i]=read();
	q=read();
	while(q--){
		a1=read(); b1=read(); a2=read(); b2=read();
		if(a1>a2)swap(a1,a2);
		if(b1>b2)swap(b1,b2);
		if(a1==a2){
			printf("%d\n",b2-b1);
			continue;			
		}//goto
		ans=1e9;//10000... //ll
		if(ce)
		{
			d=lower_bound(b+1,b+ce+1,b1)-b;
			if(b[d]&&b[d]<=b2){
				printf("%d\n",b2-b1+(a2-a1+v-1)/v);
				continue;
			}//-1 / 3 //()
//			ans=1e9;
			if(b[d]){
				ans=min(ans,b[d]-b1+b[d]-b2+(a2-a1+v-1)/v);
			}
			--d;
			if(b[d])ans=min(ans,b1-b[d]+b2-b[d]+(a2-a1+v-1)/v);
		}
		if(cl){
			d=lower_bound(a+1,a+cl+1,b1)-a;
			if(a[d]&&a[d]<=b2){
				ans=min(ans,b2-b1+a2-a1);
				printf("%d\n",ans);
				continue;
			}
			if(a[d])ans=min(ans,a[d]-b1+a[d]-b2+a2-a1);
			--d;
			if(a[d])ans=min(ans,b1-a[d]+b2-a[d]+a2-a1);
		}
		printf("%d\n",ans);
	}
}