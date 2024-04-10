#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first 
#define S second

int main(){
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		if (a <= b){
			cout << b - a;
		}else{
			int x = b * (a / b);
			for (; x < a; x += b){
			}
			cout << x - a;
		}
		cout << endl; 
	}	
}