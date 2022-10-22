#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		bool f = false;
		for (int j = 0; j <= x; j += 7){
			if ((x - j) % 3 == 0){
				f = true;
			}
		}
		cout << (f ? "YES\n" : "NO\n");
	}
}