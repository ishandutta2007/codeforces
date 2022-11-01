#include <bits/stdc++.h>

using namespace std;

int n, m, t;

char str[1005];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%s", str);
		n = strlen(str);
		
		if((n & 1) or str[0] == ')' or str[n - 1] == '('){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	
	return 0;
}