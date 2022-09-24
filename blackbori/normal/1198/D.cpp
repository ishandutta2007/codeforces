#include <bits/stdc++.h>

using namespace std;

int D[55][55][55][55];
int V[55][55];
char S[55][55];
int n;

int rectsum(int x1, int y1, int x2, int y2)
{
	return V[x2 + 1][y2 + 1] - V[x1][y2 + 1] - V[x2 + 1][y1] + V[x1][y1];
}

int main()
{
	int v, i, j, k, i1, i2, j1, j2, x1, x2, y1, y2;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%s", S[i]);
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			V[i + 1][j + 1] = V[i][j + 1] + V[i + 1][j] - V[i][j] + (S[i][j] == '#');
		}
	}
	
	for(i1=1; i1<=n; i1++) for(i2=0; i2<=n-i1; i2++){
		x1 = i2; y1 = i2 + i1 - 1;
		for(j1=1; j1<=n; j1++) for(j2=0; j2<=n-j1; j2++){
			x2 = j2; y2 = j2 + j1 - 1;
			
			if(rectsum(x1, x2, y1, y2)) v = max(i1, j1);
			else v = 0;
			
			for(k=x1; k<y1; k++){
				v = min(v, D[x1][k][x2][y2] + D[k + 1][y1][x2][y2]);
			}
			
			for(k=x2; k<y2; k++){
				v = min(v, D[x1][y1][x2][k] + D[x1][y1][k + 1][y2]);
			}
			
			D[x1][y1][x2][y2] = v;
		}
	}
	
	printf("%d\n", D[0][n - 1][0][n - 1]);
	
	return 0;
}