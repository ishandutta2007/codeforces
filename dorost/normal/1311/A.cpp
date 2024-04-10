#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		if (a == b){
			cout << 0;
		}else if(a > b){
			if ((a - b) % 2){
				cout << 2;
			}else{
				cout << 1;
			}
		}else{
			if ((b - a) % 2)
				cout << 1;
			else
				cout << 2;
		}
		cout << endl;
	}
}