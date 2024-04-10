#include <bits/stdc++.h>

using namespace std;

char str[101010];
int n;

int main()
{
	scanf("%s",str);
	
	printf("%s",str);
	
	n = strlen(str);
	
	reverse(str,str+n);
	
	printf("%s\n",str);
	
	return 0;
}