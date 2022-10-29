#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, t, k, d;
	scanf("%d%d%d%d", &n, &t, &k, &d);
	if ((n + k - 1) / k*t <= d + t)printf("NO\n");
	else printf("YES\n");
}