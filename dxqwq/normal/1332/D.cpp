#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	int m=read(),n=m;
	while(n!=(n&(-n))) n+=n&(-n);
	if(n==0)
	{
		return 0&printf("1 1\n1");
	}
	if(n==1) 
	{
		return 0&printf("3 4\n7 3 3 1\n4 8 3 6\n7 7 7 3");
	}
	if(n<100000) n*=2;
	printf("3 3\n%d %d 0\n%d %d %d\n0 0 %d",2*n-1,n-1,n,2*n-1,m,m);
	return 0;
}