#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < n - i; j++){
			cout << "  ";
		}
		for (int j = 0; j <= i; j++){
			cout << j;
			if (i == 0 && j == i);else{
				cout << ' ';
			}
		}
		for (int j = i - 1; j >= 0; j--){
			cout << j << (j > 0 ? " " : "");
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++){
			cout << "  ";
		}
		for (int j = 0; j <= n - i; j++){
			cout << j;
			if (i == n);else{
				 cout << ' ';
			}
		}
		for (int j = n - i - 1; j >= 0; j--){
			cout << j << (j > 0 ? " " : "");;
		}
		cout << endl;
	}
}