#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,k,s,e,m;

bool pos(int a)
{
	if(max(n-(a/2-a/6),0) + max(k-(a/3-a/6),0) <= a/6) return 1;
	else return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	
	s=0,e=123456789;
	
	while(s<=e){
		m=(s+e)/2;
		if(pos(m)) e=m-1;
		else s=m+1;
	}
	
	printf("%d\n",e+1);
	
	return 0;
}