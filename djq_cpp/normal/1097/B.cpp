#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, a[20];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, 1 << n) {
		int sum = 0;
		rep(j, n) if(i >> j & 1) sum += a[j];
		else sum -= a[j];
		if(sum % 360 == 0) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}