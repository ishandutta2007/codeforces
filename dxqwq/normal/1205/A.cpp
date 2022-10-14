#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[1000003];
int main()
{
	int n=read();
	if((n&1)==0) return 0&puts("NO");
	puts("YES");
	for(int i=1; i<=n; i++) if(i&1) a[i]=i*2-1,a[i+n]=i*2; else a[i]=i*2,a[i+n]=i*2-1;
	for(int i=1; i<=2*n; i++) printf("%d ",a[i]);
	return 0;
}