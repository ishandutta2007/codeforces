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
		int n, sum;
		cin >> n >> sum;
		cout << ((sum / n + 1) * (sum / n + 1)) * (sum % n) + (n - sum % n) * ((sum / n) * (sum / n)) << endl;
	}
}