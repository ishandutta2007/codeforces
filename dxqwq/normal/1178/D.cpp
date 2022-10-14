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
bool f[2003];
void init()
{
	for(int i=2; i<=2000; i++) if(f[i]) continue; else for(int j=i<<1; j<=2000; j+=i) f[j]=1;
}
int main()
{
	init();
	int n=read(),m;
	for(int i=n; i<=2000; i++) if(!f[i]) { m=i; break; }
	printf("%d\n",m);
	for(int i=1; i<n; i++) printf("%d %d\n",i,i+1);
	printf("%d %d\n",n,1);
	m-=n;
	int t=1+(n>>1);
	for(int i=1; i<=m; i++) printf("%d %d\n",i,t++); 
	return 0;
}