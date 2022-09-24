#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long n,i,j,sum,all;

long long D[2222],A[5555],B[10101];

int main()
{
	scanf("%I64d",&n);
	
	for(i=0;i<n;i++) scanf("%I64d",D+i);
	
	all = n*(n-1)/2;
	all *= (all*all);
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			A[abs(D[i]-D[j])] ++;
		}
	}
	
	for(i=0;i<=5000;i++){
		for(j=0;j<=5000;j++){
			B[i+j] += (A[i]*A[j]);
		}
	}
	
	for(i=1;i<=10000;i++){
		B[i] += B[i-1];
	}
	
	sum=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			sum += B[abs(D[i]-D[j])-1];
		}
	}
	
	
	printf("%lf",(1.0)*(sum)/all);
	
	return 0;
}