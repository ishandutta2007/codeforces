#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

vector <pii> V;
int A[55][55];
int dx[4] = {-1, -1, 0, 0}, dy[4] = {-1, 0, -1, 0};
int n, m;

bool check(int x, int y)
{
	int i;
	
	for(i=0; i<4; i++){
		x += dx[i]; y += dy[i];
		
		if(A[x][y] && A[x + 1][y] && A[x][y + 1] && A[x + 1][y + 1]){
			V.emplace_back(x, y);
			return 1;
		}
		
		x -= dx[i]; y -= dy[i];
	}
	
	return 0;
}

int main()
{
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			scanf("%d", A[i] + j);
		}
	}
	
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(A[i][j]){
				if(!check(i, j)){
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	
	printf("%d\n", (int)V.size());
	
	for(pii &t: V) printf("%d %d\n", t.first, t.second);
	
	return 0;
}