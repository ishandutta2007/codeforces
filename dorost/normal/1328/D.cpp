#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t; 
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n + 1];
		a[n] = 0;
		vector <int> v;
		cin >> a[0];
		int an = 1;
		for (int i = 1; i <= n; i++){
			if (i != n)
				cin >> a[i];
			if (a[i] != a[i - 1]){
				v.push_back(an);
				an = 1;
			}else{
				an++;
			}
		}
		if (v.size() == 1){
			cout << "1\n";
			for (int i = 0; i < n; i++){
				cout << 1 << ' ';
			}
			cout << endl;
		}else if (n % 2 == 0 || a[0] == a[n - 1]){
			cout << "2\n";
			for (int i = 0; i < n; i++){
				cout << (i % 2) + 1  << ' ';
			}
			cout << endl;
		}else if (v.size() % 2 == 0){
			cout << "2\n";
			for (int i = 0; i < v.size(); i++){
				for (int j = 0; j < v[i]; j++){
					cout << (i % 2) + 1 << ' ';
				}
			}
			cout << endl;
		}else if(v.size() != n){
			int x = 0;
			bool f = true;
			cout << 2 << endl;
			for (int i = 0; i < v.size(); i++){
				for (int j = 0; j < v[i]; j++){
					if (f && v[i] > 1){
						f = false;
						j++;
						cout << (x % 2) + 1 << ' ' << (x % 2) + 1 << ' ';
						x++;
						continue;
					}
					cout << (x %  2) + 1 << ' '; //
					x++;
				}
			}
			cout << endl;
		}else{
			cout << "3\n";
			for (int i = 0; i < v.size() - 1; i++){
				for (int j = 0; j < v[i]; j++){
					cout << (i % 2) + 1 << ' ';
				}
			}
			for (int i = 0; i < v[v.size() - 1]; i++){
				cout << 3 << ' ';
			}
			cout << endl;
		}
	}
}