#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m;

int main()
{
	scanf("%d", &n);
	if(n == 1) {
		printf("1\n1 1\n"); return 0;
	}
	m = (2 * n + 1) / 3;
	printf("%d\n", m);
	while(n % 3 != 2) {
		printf("%d %d\n", n, n); n --; m --;
	}
	rep1(i, (m + 1) / 2) printf("%d %d\n", i, (m + 1) / 2 + 1 - i);
	rep1(i, m / 2) printf("%d %d\n", (m + 1) / 2 + i, m + 1 - i);
	return 0;
}