#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int x, mx = -100000000;
	while (n--){
		cin >> x;
		if (x >= 0){
			if (sqrt(x) * floor(sqrt(x)) != x){
				mx = max(mx, x);
			}
		}else{
			mx = max(mx, x);
		}
	}
	cout << mx;
	cerr << "\nI Dont Like CF";
}