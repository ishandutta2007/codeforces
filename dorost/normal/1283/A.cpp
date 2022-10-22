#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		cout << (23 - a) * 60 + (60 - b) << endl;
	}
}