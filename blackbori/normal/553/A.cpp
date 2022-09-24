#include <bits/stdc++.h>

long long Comb[1001][1001];

int main()
{
	int k;
	scanf("%d",&k);
	
	int i,sum=0,j,a;
	
	for(i=0; i<=1000; i++){
		for(j=0; j<=1000; j++){
			if(i<j) Comb[i][j] = 0;
			else if(j==0) Comb[i][j] = 1;
			else Comb[i][j] = (Comb[i-1][j] + Comb[i-1][j-1]) % (1000000007);
		}
	}
	
	long long ans=1;
	for(i=0; i<k; i++){
		scanf("%d",&a);
		ans *= Comb[sum+a-1][a-1];
		ans %= (1000000007);
		sum+=a;
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}