#include <bits/stdc++.h>

using namespace std;

char str[5050];
int n,l,r,ans;

int main()
{
	int i,j;
	
	scanf("%s",str);
	
	n = strlen(str);
	
	for(i=0;i<n;i++){
		l = r = 0;
		for(j=i;j<n;j++){
			if(str[j] == '(') l ++, r ++;
			else if(str[j] == ')') l --, r --;
			else l --, r ++;
			
			if(l < 0) l += 2;
			if(l > r) break;
			
			if(l == 0) ans ++;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}