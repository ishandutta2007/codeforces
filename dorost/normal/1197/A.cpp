#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	cout << min(a[n - 2] - 1, n - 2);
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
}