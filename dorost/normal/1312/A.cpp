#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
 	int t = 1;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		cout << (n % m ? "NO" : "YES") << endl;
	}
}