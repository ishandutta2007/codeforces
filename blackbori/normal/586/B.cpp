#include <bits/stdc++.h>

using namespace std;

int A[101],B[101],D[101],n,ans=1e9;

int main()
{
	int i,j,a;
	scanf("%d",&n);
	
	for(i=1;i<n;i++){
		scanf("%d",&a);
		A[i]=A[i-1]+a;
	}
	
	for(i=0;i<n-1;i++) scanf("%d",B+i);
	for(i=n-2;i>=0;i--) B[i]+=B[i+1];
	
	for(i=0;i<n;i++){
		scanf("%d",D+i);
	}
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			ans = min(ans,A[i]+A[j]+B[i]+B[j]+D[i]+D[j]);
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}