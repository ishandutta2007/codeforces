#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if (k != 2 && k != 3){
		cout << "-1\n";
		return 0;
	}
	if (n <= 3){
		cout << "-1\n";
		return 0;	
	}
	if (k == 2){
		if (n == 4){
			cout << "-1\n";
			return 0;
		}
		cout << n-1 << "\n";
		for (int i = 1; i < n; i++)
			cout << i << " " << i+1 << "\n";
	}
	else{
		cout << n-1 << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << 2 << " " << 3 << "\n";
		for (int i = 4; i <= n; i++)
			cout << 3 << " " << i << "\n";
	}
	return 0;
}