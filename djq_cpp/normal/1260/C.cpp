#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int gcd(int u, int v)
{
	return v == 0 ? u : gcd(v, u % v);
}
 
void solve()
{
	int p1, p2, k;
	scanf("%d%d%d", &p1, &p2, &k);
	if(k == 1) printf("REBEL\n");
	else if(p1 == p2) printf("OBEY\n");
	else {
		int gg = gcd(p1, p2);
		p1 /= gg;
		p2 /= gg;
		if(p1 > p2) swap(p1, p2);
		if((p2 - 2) / p1 + 1 < k) printf("OBEY\n");
		else printf("REBEL\n");
	}
}
 
int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}