#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}


//72 

int d[75]=
{
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,29,31,30,31,30,31,31,30,31,30,31,
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,28,31,30,31,30,31,31,30,31,30,31
};

//=

int n,a[50];

//,}// //_ //\n/ /// //// //

int main()
{
	n=read();
	for(int i=1; i<=n; ++i)
	{
		a[i]=read();
//		if(a[i]==28)
	}
	for(int i=0; i<=48; ++i)
	{
		
		//bool char 
		//jj   //j+n
		int fl=1;
		for(int j=i; j<i+n; ++j)if(a[j-i+1]!=d[j])
		{
			fl=0;
			break;
		}
		if(fl)
		{
			puts("YES");
			exit (0);
		}
	} 
	puts("NO");
	
	return 0; //
}