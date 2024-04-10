#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, k;	cin >> k >> a >> b;
	if (a + b < k){
		cout << "-1\n";
		return 0;
	}
	int x = a/k, y = b/k;
	if (y == 0 && a % k){
		cout << "-1\n";
		return 0;
	}
	if (x == 0 && b % k){
		cout << "-1\n";
		return 0;
	}
	cout << x+y << endl;
	return 0;
}