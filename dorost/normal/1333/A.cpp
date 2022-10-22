#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n, m, b = 0, w = 0;
		cin >> n >> m;
		if (n * m % 2){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){ 
					if ((i + j) % 2 == 0){
						cout << 'B';
					}else{
						cout << 'W';
					}
				}
				cout << endl;
			}
			continue;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if(i == 0 && j == 0 && n * m % 2 == 0){
					cout << "B";
					continue;
				}
				if ((i + j) % 2 == 0){
					cout << 'W';
				}else{
					cout << 'B';
				}
			}
			cout << endl;
		}
	}
}