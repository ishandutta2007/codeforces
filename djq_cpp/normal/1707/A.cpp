#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, q, a[100005], b[100005];
void solve()
{
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	b[n] = 0;
	for(int i = n - 1; i >= 0; i --) b[i] = b[i + 1] + (a[i] > b[i + 1]);
	rep(i, n) if(a[i] <= q) printf("1");
	else if(q - 1 >= b[i + 1]) {
		printf("1"); q --;
	} else printf("0");
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0; 
}