#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int q;
	cin >> q;
	while (q--){
		ll a, b, c;
		cin >> a >> b >> c;
		ll s = a + b + c + 1;
		if ((a > s / 2 || b > s / 2 || c > s / 2) && (a && b && c)){
			cout << "NO";
		}else{
			cout << "YES";
		}
		cout << endl;
	}
}