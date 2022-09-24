#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[55][55], B[55][55], D[55][55];
int P[5050], X[5050];
int n;

bool query(int x1, int y1, int x2, int y2)
{
	int ret;
	
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf("%d", &ret);
	
	return ret;
}

int find(int p)
{
	if(p == P[p]) return p;
	
	find(P[p]);
	X[p] ^= X[P[p]];
	
	return P[p] = P[P[p]];
}

void unite(int p, int q, int v)
{
	find(p); v ^= X[p]; p = P[p];
	find(q); v ^= X[q]; q = P[q];
	P[p] = q; X[p] = v;
}

bool queryA(int x1, int y1, int x2, int y2)
{
	if(A[x1][y1] != A[x2][y2]) return 0;
	
	if(x2 == x1 + 1){
		if(A[x1 + 1][y1] == A[x1 + 1][y1 + 1]) return 1;
		if(A[x1][y1 + 1] == A[x1 + 1][y1 + 1]) return 1;
		if(A[x1][y1 + 1] == A[x1][y1 + 2]) return 1;
	}
	else{
		if(A[x1][y1 + 1] == A[x1 + 1][y1 + 1]) return 1;
		if(A[x1 + 1][y1] == A[x1 + 1][y1 + 1]) return 1;
		if(A[x1 + 1][y1] == A[x1 + 2][y1]) return 1;
	}
	
	return 0;
}

bool queryB(int x1, int y1, int x2, int y2)
{
	if(B[x1][y1] != B[x2][y2]) return 0;
	
	if(x2 == x1 + 1){
		if(B[x1 + 1][y1] == B[x1 + 1][y1 + 1]) return 1;
		if(B[x1][y1 + 1] == B[x1 + 1][y1 + 1]) return 1;
		if(B[x1][y1 + 1] == B[x1][y1 + 2]) return 1;
	}
	else{
		if(B[x1][y1 + 1] == B[x1 + 1][y1 + 1]) return 1;
		if(B[x1 + 1][y1] == B[x1 + 1][y1 + 1]) return 1;
		if(B[x1 + 1][y1] == B[x1 + 2][y1]) return 1;
	}
	
	return 0;
}

void ansA()
{
	int i, j;
	printf("!\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d", A[i][j]);
		}
		printf("\n");
	}
}

void ansB()
{
	int i, j;
	printf("!\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d", B[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i, j;
	
	scanf("%d", &n);
	
	D[1][1] = 1;
	
	for(i=1; i<=n; i++) for(j=1; j<=n; j++){
		if(i == 1 && j == 1) continue;
		if((i + j & 1) == 0){
			if(i >= 3){
				D[i][j] = !query(i - 2, j, i, j) ^ D[i - 2][j];
			}
			else if(j >= 3){
				D[i][j] = !query(i, j - 2, i, j) ^ D[i][j - 2];
			}
			else{
				D[i][j] = !query(i - 1, j - 1, i, j) ^ D[i - 1][j - 1];
			}
		}
	}
	
	for(i=0; i<n*n; i++){
		P[i] = i; X[i] = 0;
	}
	
	for(i=1; i<=n; i++) for(j=2; j<=n; j++){
		if(i == 1 && j == 2) continue;
		if(i + j & 1){
			if(i >= 3){
				unite((i - 3) * n + (j - 1), (i - 1) * n + (j - 1), !query(i - 2, j, i, j));
			}
			else if(j >= 3){
				unite((i - 1) * n + (j - 3), (i - 1) * n + (j - 1), !query(i, j - 2, i, j));
			}
			else{
				unite((i - 2) * n + (j - 2), (i - 1) * n + (j - 1), !query(i - 1, j - 1, i, j));
			}
		}
	}
	
	for(i=2; i<=n; i+=2){
		unite((i - 1) * n, i * n + 1, !query(i, 1, i + 1, 2));
	}
	
	for(i=1; i<=n; i++) for(j=1; j<=n; j++){
		if(i + j & 1){
			find((i - 1) * n + (j - 1));
			A[i][j] = X[(i - 1) * n + (j - 1)];
			B[i][j] = !A[i][j];
		}
		else A[i][j] = B[i][j] = D[i][j];
	}
	
	for(i=1; i<=n; i++) for(j=1; j<=n; j++){
		if(i + 1 <= n && j + 2 <= n && queryA(i, j, i + 1, j + 2) != queryB(i, j, i + 1, j + 2)){
			if(query(i, j, i + 1, j + 2) == queryA(i, j, i + 1, j + 2)) ansA();
			else ansB();
			return 0;
		}
	}
	
	for(i=1; i<=n; i++) for(j=1; j<=n; j++){
		if(i + 2 <= n && j + 1 <= n && queryA(i, j, i + 2, j + 1) != queryB(i, j, i + 2, j + 1)){
			if(query(i, j, i + 2, j + 1) == queryA(i, j, i + 2, j + 1)) ansA();
			else ansB();
			return 0;
		}
	}
	
	return 0;
}