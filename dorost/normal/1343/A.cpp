#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	vector <int> v;
	int x = 0;
	int k = 0;
	while (x <= 1e9){
		x += pow(2, k);
		if (k != 0)
			v.push_back(x);
		k++;
	}
//	cerr << k << endl;
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < v.size(); i++){
			if (n % v[i] == 0){
				cout << n / v[i] << endl;
				break;
			}
		}
	}
}