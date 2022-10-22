#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n;
double x1[MAXN],x2[MAXN],x3[MAXN];
double prob;

int main () {
	scanf("%d",&n);
	for(register int i = 1;i <= n; ++i) {
		scanf("%lf",&prob);
		x1[i] = (x1[i - 1] + 1) * prob;
		x2[i] = x2[i - 1] + (2 * x1[i - 1] + 1) * prob;
		//x3[i] = x3[i - 1] + (3 * x2[i - 1] + 3 * x1[i - 1] + 1) * prob;
	}
	printf("%.10lf",x2[n]);
	return 0;
}