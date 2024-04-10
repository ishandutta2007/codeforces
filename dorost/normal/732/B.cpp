#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	cin >> a[0];
	int sum = 0;
	for (int i = 1; i < n; i++){
		cin >> a[i];
		int x = a[i];
		a[i] = max(x, k - a[i - 1]);
		sum += a[i] - x;
	}
	cout << sum << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}