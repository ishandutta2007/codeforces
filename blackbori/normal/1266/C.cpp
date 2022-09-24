#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

int main()
{
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	if(n == 1){
		if(m == 1){
			printf("0\n");
			return 0;
		}
		for(i = 1; i <= m; i ++){
			printf("%d ", i + 1);
		}
		printf("\n");
		return 0;
	}
	else if(m == 1){
		for(i = 1; i <= n; i ++){
			printf("%d\n", i + 1);
		}
		return 0;
	}
	
	for(i = 1; i <= n; i ++){
		for(j = 1; j <= m; j ++){
			printf("%d ", i * (n + j));
		}
		printf("\n");
	}
	
	return 0;
}