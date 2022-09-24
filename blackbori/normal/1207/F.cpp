#include <bits/stdc++.h>

using namespace std;

int D[777][777];
int A[505050];
int n;

int main()
{
	int i, j, t, x, y, s;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d%d%d", &t, &x, &y);
		
		if(t == 1){
			A[x] += y;
			for(j=1; j<=700; j++){
				D[j][x % j] += y;
			}
		}
		else{
			if(x <= 700) printf("%d\n", D[x][y]);
			else{
				for(j=y, s=0; j<=5e5; j+=x){
					s += A[j];
				}
				printf("%d\n", s);
			}
		}
	}
	
	return 0;
}