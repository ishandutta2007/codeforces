#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
 	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		if (a + b == 0){
			cout << "YES\n";
			continue;
		}
		if ((a + b) % 3){
			cout << "NO\n";
			continue;
		}
		int ans = (a + b) / 3;
		if (a >= ans && b >= ans){
			cout << "YES\n";
		}else
			cout << "NO\n";
	}
}