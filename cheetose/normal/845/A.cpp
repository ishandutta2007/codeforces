#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n;
	int a[200];
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", a + i);
	sort(a, a + 2 * n);
	if (a[n - 1] == a[n]) puts("NO");
	else puts("YES");
}