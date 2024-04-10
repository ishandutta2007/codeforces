#include <bits/stdc++.h>

long long L[52]; //L[i] : length of the list when n=i

long long N, K;

int ans[52];

int main()
{
	scanf("%I64d %I64d",&N,&K);
	
	int i;
	L[0] = 1; L[1] = 1;
	for(i=2; i<=N; i++) L[i] = L[i-1] + L[i-2];
	
	for(i=1; i<=N;){
		if(K > L[N-i]){
			ans[i] = i+1; ans[i+1] = i;
			K -= L[N-i];
			i+=2;
		}
		else{
			ans[i] = i;
			i++;
		}
	}
	
	for(i=1; i<=N; i++) printf("%d ",ans[i]);
	printf("\n");
	
	return 0;
}