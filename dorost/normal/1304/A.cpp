#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if ((y - x) % (a + b) == 0){
			cout << (y - x) / (a + b);
		}else{
			cout << -1;
		}
		cout << endl;
	}
}