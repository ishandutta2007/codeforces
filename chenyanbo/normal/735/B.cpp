#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int x,y,n,a[100001];
long long o,u;
int main()
{
	n=read(),x=read(),y=read(); //, ,, ; ;;
	for(int i=1; i<=n; ++i)a[i]=read();// &(x+i)
	sort(a+1,a+n+1);
	if(x>y)swap(x,y);
	for(int i=n; i>n-x; --i)o+=a[i]; //n-x
	for(int i=n-x; i>n-x-y; --i)u+=a[i];
//	printf("%.8lf",o/x+u/y);//double  //f
printf("%.8lf\n",(double)o/x+(double)u/y);
//\n \r\n
}