#include <bits/stdc++.h>

using namespace std;

int D[100003];
int L[100003],R[100003];

int N;

int main()
{
	scanf("%d",&N);
	
	int i,ans=0,k;
	
	for(i=1; i<=N; i++) scanf("%d",D+i);
	L[0] = N+1;
	for(i=1; i<=N; i++) L[i] = min(L[i-1],D[i]+(N-i+1));
	R[N+1] = N+1;
	for(i=N; i>=1; i--) R[i] = min(R[i+1],D[i]+i);
	
	for(i=1; i<=N; i++){
		k = min(L[i]-(N-i+1),R[i]-i);
		ans = max(ans,k);
	}
	
	printf("%d\n",ans);
	
	return 0;
}