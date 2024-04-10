#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll gen, num;
	scanf("%I64d%I64d", &gen, &num);
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		v.push_back(zb);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int r = 0;
	for (ll i = 1;; i++)
	{
		if (i % 2 == 1) { if (gen < i*(i - 1) / 2 + 1)break; }
		else if (gen < i*i / 2)break;
		r = i;
	}
	ll ans = 0;
	for (int i = 0; i < min(r, int(v.size())); i++)ans += v[i];
	printf("%I64d\n", ans);
}