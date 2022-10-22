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
		int n;
		cin >> n;
		bool f = false;
		for (int i = 3; i <= 360; i++){
			if (360 % i)
				continue;
			if (((i - 2) * 180) / i == n)
				f = true;
		}
		cout << (f ? "YES" : "NO") << endl;
	}
}