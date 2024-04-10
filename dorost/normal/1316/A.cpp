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
		int n, m, x, sum = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> x;
			sum += x;
		}
		cout << min (m, sum) << endl;
	}
}