#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[202020];
int n;

int main()
{
	int i;
	
	scanf("%d", &n);
	
	if(~n & 1){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	
	for(i=0; i<n; i++){
		if(i & 1){
			A[i] = i * 2 + 1;
			A[n + i] = i * 2 + 2;
		}
		else{
			A[i] = i * 2 + 2;
			A[n + i] = i * 2 + 1;
		}
	}
	
	for(i=0; i<n+n; i++){
		printf("%d ", A[i]);
	}
	
	printf("\n");
	
	return 0;
}