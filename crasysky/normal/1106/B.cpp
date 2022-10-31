#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1000006
#define fi first
#define se second
using namespace std;
pair <int, pair <int, int> > a[maxn];
int mp[maxn];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i].se.se);
		a[i].se.fi = i;
	}
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i].fi);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i)
		mp[a[i].se.fi] = i;
	int p = 1;
	for (int i = 1; i <= m; ++ i){
		int kind, num;
		scanf("%d %d", &kind, &num);
		kind = mp[kind];
		long long ans = 0;
		if (num >= a[kind].se.se){
			num -= a[kind].se.se;
			ans += 1LL * a[kind].fi * a[kind].se.se;
			a[kind].se.se = 0;
		}
		else{
			ans += 1LL * a[kind].fi * num;
			a[kind].se.se -= num;
			num = 0;
		}
		while (p <= n && num){
			if (num >= a[p].se.se){
				num -= a[p].se.se;
				ans += 1LL * a[p].fi * a[p].se.se;
				a[p].se.se = 0;
				++ p;
			}
			else{
				ans += 1LL * a[p].fi * num;
				a[p].se.se -= num;
				num = 0;
			}
		}
		if (num)
			printf("0\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}