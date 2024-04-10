#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

#include <cctype>
#define DBG(FMT...) fprintf(stderr , FMT)

using namespace std;

int n , k;
int a[100000 + 5];
vector <int> v;
int main() {
	cin >> n >> k;
	int ans = 0;
	for(int i = 1;i <= n;i++) cin >> a[i] , ans += a[i] / 10;
	
	for(int i = 1;i <= n;i++) v . push_back(a[i] % 10);
	
	sort(v . begin() , v . end());
	reverse(v . begin() , v . end());
	int tt = 0;
	for(int x : v) {
		if(k >= 10 - x) {
			k -= (10 - x);
			++ans;
		}
	}
	
	if(k >= 10) {
		ans += (k / 10);
		k -= (k / 10) * 10;
	}
	
	if(ans > 10 * n) ans = 10 * n;
	cout << ans << endl;
	return 0;
}