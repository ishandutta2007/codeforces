#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin  >> n;
		int x = 0, y = 0, z;
		for (int i = 0; i < n; i++){
			cin >> z;
			z % 2 ? x ++ : y ++;
		}
		int m;
		cin >> m;
		int a = 0, b = 0, c;
		for (int i = 0; i < m; i++){
			cin >> c;
			c % 2 ? a ++ : b++;
		}
		cout << a * x + b * y << endl; 
	}
}