#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	if (a[n - 1] <= 25)puts("0");
	else printf("%d", a[n - 1] - 25);
}