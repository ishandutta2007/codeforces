/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector <int> v;
		for (int i = n - 1; i >= 0; i--){
			if (a[i] != b[i]){
				if (a[0] != a[i]){
					v.push_back (1);
					if (a[0] == '0')
						a[0] = '1';
					else
						a[0] = '0';
				}
				v.push_back(i + 1);
				for (int j = 0; j <= i; j++){
					if (a[j] == '0')
						a[j] = '1';
					else
						a[j] = '0';
				}
				reverse (a.begin(), a.begin() + i + 1);
			}
		}
		cout << v.size() << ' ';
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << ' ';
		}
		cout << endl;
	}
}