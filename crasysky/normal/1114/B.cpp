#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
pair <int, int> a[1000006];
int b[1000006];
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i].fi);
		a[i].se = i;
    }
    sort(a + 1, a + 1 + n);
	long long ans = 0;
    for (int i = n; i >= n - m * k + 1; -- i)
		b[a[i].se] = 1, ans += a[i].fi;
	cout << ans << endl;
	for (int i = 1, c = 0, cnt = 0; i <= n; ++ i){
		c += b[i];
		if (c >= m && cnt < k - 1){
			printf("%d ", i);
			++ cnt;
			c = 0;
		}
	}
}