#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define B 600
#define NB 170
ll a[200000], b[200000];//x is 64-bit variable;
ll n, d, x;
ll getNextX() {
x = (x * 37 + 10007) % 1000000007;
return x;
}
void initAB() {
	int i;
	for (i = 0; i < n; i = i + 1) {
		a[i] = i + 1;
	}
	for (i = 0; i < n; i = i + 1) {
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for (i = 0; i < n; i = i + 1) {
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (i = 0; i < n; i = i + 1) {
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}
ll ans[200000];
int main()
{
	scanf("%I64d%I64d%I64d", &n, &d, &x);
	initAB();
	if (d >= B)
	{
		set<pii>se;
		for (int i = 0; i < n; i++)
		{
			se.insert(make_pair(a[i], i));
			set<pii>::iterator it = se.end();
			ll ans = 0;
			for (;;)
			{
				if (it == se.begin())break;
				it--;
				pii z = *it;
				if (b[i - z.second])
				{
					ans = z.first;
					break;
				}
			}
			printf("%I64d\n", ans);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (b[i])
			{
				for (int j = 0; j < n; j++)ans[i + j] = max(ans[i + j], a[j]);
			}
		}
		for (int i = 0; i < n; i++)printf("%I64d\n", ans[i]);
	}
}