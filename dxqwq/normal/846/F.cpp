#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int lst[1000003];
signed main()
{
	int n=read();
	long long ans=0;
	for(int i=1,x; i<=n; i++) x=read(),ans+=1ll*(i-lst[x])*(n-i+1),lst[x]=i;
	printf("%.10lf\n",(2.0*ans/n-1)/n);
	return 0;
}