#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char A[101010], B[101010];
ll n, a, b, c, d;

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	scanf("%s%s", A, B);
	
	for(i=0; i<n; i++){
		if(A[i] == '0' && B[i] == '0') a ++;
		else if(A[i] == '0' && B[i] == '1') b ++;
		else if(A[i] == '1' && B[i] == '0') c ++;
		else if(A[i] == '1' && B[i] == '1') d ++;
	}
	
	printf("%lld\n", a * c + a * d + b * c);
	
	return 0;
}