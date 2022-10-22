#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if (n % 2){
			cout << '7';
			for (int i = 0; i < n - 3; i += 2)
				cout << '1';
		}else{
			for (int i = 0; i < n; i += 2)
				cout << '1';
		}
		cout << endl;
	}
}