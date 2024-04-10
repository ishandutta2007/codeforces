#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n < 3){
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	if (a[0] == a[n - 1]){
		cout << "0\n";
		return 0;
	}
	cout << (lower_bound(a, a + n, a[n - 1]) - upper_bound(a, a + n, a[0])) << "\n";
	return 0;
}