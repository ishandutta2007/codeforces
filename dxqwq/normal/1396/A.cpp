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
int main(){
	int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    if(n==1) printf("1 1\n%lld\n1 1\n0\n1 1\n0\n",-1LL*a[1]),exit(0);
    printf("1 1\n%lld\n2 %d\n",1LL*a[1]*(n-1),n);
    for(int i=2; i<=n; i++) printf("%lld ",1LL*a[i]*(n-1));
    printf("\n1 %d\n",n);
    for(int i=1; i<=n; i++) printf("%lld ",-1LL*a[i]*n);
	return 0;
}