#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, mn = 100000000, ans;
	cin >> n;
	for (int i = 1; i < 10000; i++){
		for (int j = 1; j < 10000; j++){
			if (i * j >= n && i * j - j < n && i * j - i < n){
				if (abs(i - j) < mn){
					mn = abs(i - j);
					ans = i * 2 + j * 2;
				}
			}
		}
	}
	cout << ans;
}