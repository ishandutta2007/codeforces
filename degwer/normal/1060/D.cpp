#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[101010], b[101010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%I64d%I64d", &a[i], &b[i]);
	sort(a, a + num), sort(b, b + num);
	ll ans = 0;
	for (int i = 0; i < num; i++)ans += max(a[i], b[i]);
	printf("%I64d\n", ans + num);
}