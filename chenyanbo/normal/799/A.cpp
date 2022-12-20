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
int s,g,x,n,t,k,d,a1,b,c;
int main()
{ //; , ///pow(2,1024.)    //1024    //sqrt(-1)  sqr
	n=read(); t=read(); k=read(); d=read();
	a1=(n-1)/k*t+t;
	x=d/t*k;
	//const
	n-=x;    // int
	g=d/t*t;// <<1  >>1   -5 ..5 
	b=n/(2*k);
	c=b*t;
	n-=b*k*2;
	// <<1<<1  //()   //+5 -5  5//shuru
	s=d+c;
	if(n>0 && n<=k)s+=t-d+g;
	else if(n>k)s+=t;
	if(s<a1)puts("YES");else puts("NO");
	// \n   // \r\n
}