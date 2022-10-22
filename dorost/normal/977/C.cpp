#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	if (k == n){
		cout << *max_element(a, a + n);
		return 0;
	}else if (k == 0){
		if (*min_element(a, a + n) == 1)
			cout << -1;
		else
			cout << *min_element(a, a + n) - 1;
		return 0;
	}
	sort(a, a + n);
	if (a[k] == a[k - 1])
		cout << -1;
	else
		cout << a[k - 1];
}