#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 3;

int n, a[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = *max_element(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += mx-a[i];
	cout << ans << endl;
	return 0;
}