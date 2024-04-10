/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	vector <int> v;
	for (int s = 1; s <= 9; s++) {
		for (int i = 0; i < pow(2, s); i++) {
			int x = i;
			string t;
			for (int j = 0; j < s; j++) {
				if (x % 2)
					t += '7';
				else
					t += '4';
				x /= 2;
			}
			v.push_back(stoi(t));
		}
	}
	sort(v.begin(), v.end());
	int n;
	cin >> n;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == n) 
			return cout << i + 1, 0;
	}
}