#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int main()
{int x,y; 
	x=read(); y=read();
	if(x<=y-2 || !y){
		puts("No");
		return 0;
	}
	
	
	if(y==1){
		if(x)puts("No");
		else puts("Yes");
		exit(0);
	}
	if((x-y+1)&1)puts("No");
	else puts("Yes");
}