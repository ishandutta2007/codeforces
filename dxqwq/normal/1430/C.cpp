#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	for(int T=read(); T--;)
	{
		int n=read();
		puts("2");
		printf("%d %d\n",n,n-1);
		for(int i=n; i>=3; i--) printf("%d %d\n",i,i-2);
	}
	return 0;
}