#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, x, a = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		if(x < 0)
			a++;
		cin >> x;
	}
	cout << (a < 2 || a > n - 2 ? "YES" : "NO");
}