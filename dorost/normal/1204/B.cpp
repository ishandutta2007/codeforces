#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const bool T = true;
const bool F = false;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a = 1, ans = 0;
	for (int i = 0; i < m - 1; i++){
		a *= 2;
		ans += a; 
	}
	ans += n - m + 1;
	cout << ans << ' ';
	ans = 0;
	a = 1;
	for (int i = 0; i < k - 1; i++){
		a *= 2;
		ans += a; 
	}
	ans += (n - k) * a + 1;
	cout << ans;
}