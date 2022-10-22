#include<iostream>

using namespace std;

int main(){
	int n;	cin >> n;
	if (n == 1){
		int x;	cin >> x;
		if (x)
			cout << "YES\n";
		else
			cout << "NO\n";
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		if (x)
			cnt++;
	}
	if (cnt == n - 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}