#include <bits/stdc++.h>

using namespace std;

int N;
int D[100003];

int GCD(int a,int b)
{
	if(a==0) return b;
	else return GCD(b%a,a);
}

bool Can(int a)
{
	while(a%2==0) a/=2;
	while(a%3==0) a/=3;
	
	return a == 1;
}

int main()
{
	scanf("%d",&N);
	
	int i,gcd;
	for(i=0; i<N; i++) scanf("%d",D+i);
	
	gcd=0;
	for(i=0; i<N; i++) gcd = GCD(gcd,D[i]);
	
	for(i=0; i<N; i++) D[i] /= gcd;
	
	for(i=0; i<N; i++){
		if(!Can(D[i])){
			printf("No\n");
			return 0;
		}		
	}
	
	printf("Yes\n");
	
	return 0;
}