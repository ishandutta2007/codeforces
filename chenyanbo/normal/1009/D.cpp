#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

int n,m,a[100004],b[100004],k;

int main()
{
	n=read(); m=read();
	m-=n-1;
	if(m<0){
		puts("Impossible");
		exit(0);
	}
	for(int i=3;i<=n;++i){
		for(int j=2;j<i;++j)if(gcd(i,j)==1){
//			++k;
			a[++k]=i; b[k]=j;
			if(k>=m)goto lll;
		}
	}
	lll:;
	if(k<m){
		puts("Impossible");return 0;
//		exit(0);
	}
	puts("Possible");
	for(int i=2;i<=n;++i)printf("1 %d\n",i);
	for(int i=1;i<=m;++i)printf("%d %d\n",b[i],a[i]);
}