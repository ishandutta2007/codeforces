#include <bits/stdc++.h>

using namespace std;

char str[5050];
int a,b,c,i;

int main()
{
	scanf("%s",str);
	
	for(i=0;str[i];i++){
		if(str[i] != 'a') break;
		a ++;
	}
	
	for(;str[i];i++){
		if(str[i] != 'b') break;
		b ++;
	}
	
	for(;str[i];i++){
		if(str[i] != 'c') break;
		c ++;
	}
	
	if(str[i] || a == 0 || b == 0 || (c != a && c != b)) printf("NO\n");
	else printf("YES\n");
	
	return 0;
}