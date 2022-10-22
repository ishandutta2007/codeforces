#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e6 + 10;

int n, val[MAXN], d[1<<23];

int main(){
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		d[val[i]] = val[i];
	}		
	for (int i = 1; i < (1<<22); i++)
		if (d[i] == -1)
			for (int j = 0; j < 22; j++)
				if ((i >> j) & 1)
					if (~d[i ^ (1<<j)]){
						d[i] = d[i^(1<<j)];
						break;
					}
	for (int i = 0; i < n; i++){
		int z = ~val[i];
		z &= (1<<22) - 1;
		printf("%d ", d[z]);
	}
	printf("\n");
	return 0;	
}