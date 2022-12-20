#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
long long n,k;
int main()
{
	cin>>n>>k;//max min( //leixing //ma mi  //aba fabs  ab //_  //(a)  (-(a))
	for(int i=1; i<=k; ++i)//if(n%i!=i-1)
	{
		if(n%i!=i-1){
		
		puts("No");
		exit(0);}//printf  putchar  gets//
		if(i>1000000){
			puts("Yes");
			return 0;
		}
	}
	puts("Yes");
}