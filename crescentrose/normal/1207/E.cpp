#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int a[2][101];
int main(){
	for (int i = 1; i <= 100; i ++)
		a[0][i] = i, a[1][i] = ((1 << 7) * i) + i;
	printf("?");
	for (int i = 1; i <= 100; i ++)
	{
		printf(" %d", a[0][i]);
	}
	printf("\n");
	
	printf("?");
	for (int i = 1; i <= 100; i ++)
	{
		printf(" %d", a[1][i]);
	}
	printf("\n");
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	printf("!");
	for (int i = 1; i <= 100; i ++)
		for (int j =1; j <= 100; j ++)
			if ((x^a[0][i]) == (y ^ a[1][j]) && (x ^ a[0][i] < (1 << 14))) {
				printf(" %d\n", x ^a[0][i]);
				fflush(stdout);
				return 0;
			}
	return 0;
}