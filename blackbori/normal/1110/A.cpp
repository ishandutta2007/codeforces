#include <bits/stdc++.h>

using namespace std;

int A[101010];
int b, k, s;

int main()
{
	int i;
	
	scanf("%d%d", &b, &k);
	
	for(i=1; i<=k; i++){
		scanf("%d", A + i);
		s += A[i];
	}
	
	if(b & 1){
		if(s & 1) printf("odd\n");
		else printf("even\n");
	}
	else{
		if(A[k] & 1) printf("odd\n");
		else printf("even\n");
	}
	
	return 0;
}