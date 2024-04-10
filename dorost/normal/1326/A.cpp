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
		int n;
		cin >> n;
		if (n == 1){
			cout << -1;
		}else{
			for (int i = 0; i < n - 1; i ++)
				cout << 3;
			cout << 4;
		}
		cout << endl;
	}
}