#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n * 2];
		n *= 2;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort (a, a + n);
		cout << a[n / 2] - a[n / 2 - 1] << endl; 
	}
}