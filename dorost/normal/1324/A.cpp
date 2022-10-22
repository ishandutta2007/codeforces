#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
 	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		cin >> a[0];
		int x = a[0] % 2;
		bool f = true;
		for (int i = 1; i < n; i++){
			cin >> a[i];
			if (a[i] % 2 != x)
				f = false;
		}
		cout << (f ? "YES" : "NO") << endl;
	}
}