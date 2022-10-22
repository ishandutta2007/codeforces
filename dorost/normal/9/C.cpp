#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	vector <int> v;
	int x = 1;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < x; j++){
			string s = "1";
			int l = j;
			for (int k = 0; k < i; k++){
				s += ('0' + (l % 2));
				l /= 2;
			}
			v.push_back(stoi(s));
		}
		x *= 2;
	}
	v.push_back(1000000000);
	v.push_back(1000000001);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < v.size(); i++){
		if (v[i] <= n)
			ans ++;
	}
	cout << ans;
}