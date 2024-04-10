#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int g,n,x1,x2;
struct node {
	int i, w;
	bool operator < (const node &a)const{
		return w>a.w;
	}
}a[300005];
//sort shuchu//????
int main()
{
	n=read(); x1=read(); x2=read();
	for(int i=1; i<=n; ++i){
		a[i].i=i;
		a[i].w=read();
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i){
		if((double)x1/i<=a[i].w+1e-9){
			g=i;
			break;
		}
	}
	if(g==n||!g){
		puts("No");
		exit(0);
	}

	for(int i=g+1; i<=n; ++i){
		if((double)x2/(i-g)<=a[i].w+1e-9){
			puts("Yes");
			printf("%d %d\n",g,i-g);
			for(int i=1; i<=g; ++i)printf("%d ",a[i].i);puts("");
			for(int ii=g+1; ii<=i; ++ii)printf("%d ",a[ii].i);
			return 0;
		}
	}
	
		
	g=0;
	
	for(int i=1; i<=n; ++i){
		if((double)x2/i<=a[i].w+1e-9){
			g=i;
			break;
		}
	}
	if(g==n||!g){
		puts("No");
		exit(0);
	}
	for(int i=g+1; i<=n; ++i){
		if((double)x1/(i-g)<=a[i].w+1e-9){
			puts("Yes");
			printf("%d %d\n",i-g,g);
			for(int ii=g+1; ii<=i; ++ii)printf("%d ",a[ii].i);puts("");
			for(int i=1; i<=g; ++i)printf("%d ",a[i].i);
			
			return 0;
		}
	}
	
	
	puts("No");
}