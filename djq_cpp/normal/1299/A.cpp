#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, a[100005];
int orl[100005], orr[100005];
 
int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	orl[0] = 0;
	rep(i, n - 1) orl[i + 1] = orl[i] | a[i];
	orr[n - 1] = 0;
	for(int i = n - 1; i > 0; i --) orr[i - 1] = orr[i] | a[i];
	int ret = 0;
	rep(i, n) ret = max(ret, (a[i] | orl[i] | orr[i]) - (orl[i] | orr[i]));
	int pos = -1;
	rep(i, n) if(ret == (a[i] | orl[i] | orr[i]) - (orl[i] | orr[i])) pos = i;
	rotate(a, a + pos, a + pos + 1);
	rep(i, n) printf("%d ", a[i]);
	return 0;
}