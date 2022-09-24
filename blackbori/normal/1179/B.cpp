#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
	int i;
	
	scanf("%d%d", &n, &m);
	
	for(i=0; i<n*m/2; i++){
		printf("%d %d\n", i / m + 1, i % m + 1);
		printf("%d %d\n", (n * m - 1 - i) / m + 1, (n * m - 1 - i) % m + 1);
	}
	
	if(n * m & 1) printf("%d %d\n", i / m + 1, i % m + 1);
	
	return 0;
}