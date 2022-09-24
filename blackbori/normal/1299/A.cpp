#include <bits/stdc++.h>

using namespace std;

int A[101010], D[33];
int n, m, x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i, j, s;

	scanf("%d", &n);

	for(i = 1; i <= n; i ++){
		scanf("%d", A + i);
		for(j = 0; j < 30; j ++){
			if(A[i] & (1 << j)) D[j] ++;
		}
	}

	for(i = 1, m = -1; i <= n; i ++){
		for(j = 0, s = 0; j < 30; j ++){
			if(A[i] & (1 << j)){
				if(D[j] == 1) s |= 1 << j;
			}
		}
		if(s > m) m = s, x = i;
	}

	printf("%d ", A[x]);

	for(i = 1; i <= n; i ++){
		if(i != x) printf("%d ", A[i]);
	}

	printf("\n");

	return 0;
}