/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 2012345678;

int32_t main(){
	vector <int> v = {0};
	int cnt = 1, x = 0;
	while (x < M){
		x += cnt;
		cnt++;
		v.push_back(x);
	}
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		int n = abs(a - b), an = 0;
		if (n == 0)
			cout << 0 << endl;
		else if (n == 1)
			cout << 1 << endl;
		else if (n == 2)
			cout << 3 << endl;
		else if (n == 3)
			cout << 2 << endl;
		else if (n == 4)
			cout << 3 << endl;
		else {
			for (int i = 0; i < v.size(); i++){
				if (v[i] >= n && v[i] % 2 == n % 2){
					an = i;
					break;
				}
			}
			cout << an << endl;
		}
	}
}