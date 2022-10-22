#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n; 
	cout << "1 ";
	int x = 1, y = n - 1;
	for (int i = 1; i < n; i++){
		if (i % 2){
			x += y;
		}else{
			x -= y;
		}
		cout << x << ' ';
		y --;
	}
}