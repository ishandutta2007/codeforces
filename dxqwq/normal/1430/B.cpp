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
		int n=read(),k=read()+1;
		for(int i=1; i<=n; i++) a[i]=read();
		sort(a+1,a+n+1);
		long long sum=0;
		for(int i=n; k>=1&&i>=1; i--,k--) sum+=a[i];
		printf("%lld\n",sum);
	}
	return 0;
}