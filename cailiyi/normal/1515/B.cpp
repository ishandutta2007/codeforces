#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n,S,sq;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n&1) {puts("NO");continue;}
		S=n>>1;
		sq=sqrt(S);
		if(sq*sq==S) {puts("YES");continue;}
		if(S&1) {puts("NO");continue;}
		S>>=1;
		sq=sqrt(S);
		if(sq*sq==S) {puts("YES");continue;}
		puts("NO");
	}
	return 0;
}