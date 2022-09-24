#include <bits/stdc++.h>

using namespace std;

int A[1010], B[1010];
int n, s;

int main()
{
	int i;
	
	scanf("%d%d", &n, &s);
	
	for(i=1; i<=n; i++){
		scanf("%d", A + i);
	}
	
	for(i=1; i<=n; i++){
		scanf("%d", B + i);
	}
	
	if(A[1] && A[s]){
		printf("YES\n");
		return 0;
	}
	
	for(i=s; i<=n; i++){
		if(A[1] && B[s] && (A[i] && B[i])) break;
	}
	
	if(i > n) printf("NO\n");
	else printf("YES\n");
	
	return 0;
}