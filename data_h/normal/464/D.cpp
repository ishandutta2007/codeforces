#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int SN = 600;
const int N = 100000;
const double eps = 1e-12;

double f[SN + 5], quick[N + 5];
double result = 0;
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	memset(f, 0, sizeof(f));
	f[1] = 1;
	
	for(int i = 1; i <= SN; i++) {
		quick[i] = i * (0.5 + 1. / (i + 1));
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = SN; j >= 1; j--) {
			if (f[j] < 1e-100) {
				f[j] = 0;
				continue;
			}
			result += f[j] * quick[j];
			double temp = f[j] / k / (j + 1);
			f[j] -= temp;
			f[j + 1] += temp;
		}
	}	
	
	printf("%.12f\n", result);
	return 0;
}