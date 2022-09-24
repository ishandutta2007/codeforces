#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	if(n==1 && m==1) printf("1\n");
	else printf("%d\n",(m-1) >= (n-(m+1)+1)? (m-1) : (m+1));
	
	return 0;
}