#include <bits/stdc++.h>

using namespace std;

char S[101010];
int L[101010][2], R[101010][2];
int D[101010];
int n, k;

int main()
{
	int i;
	
	scanf("%d%d%s", &n, &k, S + 1);
	
	for(i=1; i<=n; i++){
		D[i] = D[i - 1] + (S[i] == '1');
	}
	
	// 1
	
	for(i=k; i<=n; i++){
		if((D[n] - D[i] == n - i && D[i - k] == i - k) ||
			(D[n] - D[i] == 0 && D[i - k] == 0)){
			printf("tokitsukaze\n");
			return 0;
		}
	}
	
	// 2
	
	for(i=0; i<=k; i++){
		L[i][0] = 1; L[i][1] = 1;
	}
	
	for(; i<=n; i++){
		if(S[i] == '0' && L[i - 1][0]) L[i][0] = 1;
		if(S[i] == '1' && L[i - 1][1]) L[i][1] = 1;
		if(D[i - k] == 0) L[i][0] = 1;
		if(D[i - k] == i - k) L[i][1] = 1;
	}
	
	for(i=n+1; i>n-k; i--){
		R[i][0] = 1; R[i][1] = 1;
	}
	
	for(; i>=1; i--){
		if(S[i] == '0' && R[i + 1][0]) R[i][0] = 1;
		if(S[i] == '1' && R[i + 1][1]) R[i][1] = 1;
		if(D[n] - D[i + k - 1] == 0) R[i][0] = 1;
		if(D[n] - D[i + k - 1] == n - (i + k - 1)) R[i][1] = 1;
	}
	
	for(i=k; i<=n; i++){
		if(!(L[i - k][0] && D[n] - D[i] == 0) && !(R[i + 1][0] && D[i - k] == 0)) break;
		if(!(L[i - k][1] && D[n] - D[i] == n - i) && !(R[i + 1][1] && D[i - k] == i - k)) break;
	}
	
	if(i > n) printf("quailty\n");
	else printf("once again\n");
	
	return 0;
}