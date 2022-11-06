#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n, l, v1, v2, k; 
	scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k); 
	int cnt = (n + k - 1) / k; 
	printf("%.8lf\n", (double)l * (((double)cnt * 2 - 1) * v2 + v1) / (v2 + ((double)cnt * 2 - 1) * v1) / v2);
	return 0; 
}