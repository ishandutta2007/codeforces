#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n], b[n], ans[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
			ans[i] = a[i] + b[i];
		}
		sort (a, a + n);
		sort (b, b + n);
			for (int i = 0; i < n; i++)
				cout << a[i] << ' ';
			cout << endl;
			for (int i = 0; i < n; i++)
				cout << b[i] << ' ';
		cout << endl;
	}
}