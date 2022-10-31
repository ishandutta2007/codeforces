#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 11111;

int n, k;
int a[N][4];

int main() {
	scanf("%d %d", &n, &k);
	a[1][0] = 1, a[1][1] = 2, a[1][2] = 3, a[1][3] = 5;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j < 4; j++) {
			a[i][j] = a[i - 1][j] + 6;
		}
	printf("%d\n", a[n][3] * k);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 4; j++) {
			printf("%d%c", a[i][j] * k, j == 3 ? '\n' : ' ');
		}
	}
	
	return 0;
}