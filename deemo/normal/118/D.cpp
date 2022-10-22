#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

const int max_n = 100 + 2;
const int max_k = 10 + 2;
const int MOD = 1e8;

int d[max_n][max_n][3];
int a, b, k[2];

int main(){
	scanf("%d%d%d%d", &a, &b, &k[0], &k[1]);
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++){
			if (i == j && i == 0){
				d[i][j][0] = d[i][j][1] = 1;
				continue;	
			}
			for (int z = 0; z < 2; z++){
				for (int v = 1; v <= k[z] && v <= ({int ret; if (z == 0)	ret = i; else ret = j; ret;	}); v++)
					if (z == 0)
						d[i][j][z] = (d[i][j][z] + d[i-v][j][1]) % MOD;
					else
						d[i][j][z] = (d[i][j][z] + d[i][j-v][0]) % MOD;
			}
		}
	printf("%d\n", (d[a][b][0] + d[a][b][1]) % MOD);
	return 0;
}